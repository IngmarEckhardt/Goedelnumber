#include "Primes.h"
#include "PrimeRepository.h"
#include "SieveOfEratosthenes.h"


Primes::Primes(bool newprimes) {

    if (newprimes) {
        newPrimes();
    } else {
        listOfPrimes = PrimeRepository::readPrimesFromFile();
        if (listOfPrimes.empty()) {
            newPrimes();
        }
    }
}


unsigned long int Primes::getPrime(const unsigned int numberOfPrime) {

return listOfPrimes[numberOfPrime];
}


void Primes::newPrimes() {
    SieveOfErastosthenes erastosthenes;
    listOfPrimes = erastosthenes.yieldPrimes(100.000);
    PrimeRepository::writePrimeVectorToFile(listOfPrimes);
}