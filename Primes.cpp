#include <iostream>
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


unsigned long int Primes::getPrime(const unsigned int numberOfPrime, bool &debugflag) {

    if (debugflag) {
        std::cout << "Serving Prime \"" << listOfPrimes[numberOfPrime] << "\" out of Prime-Vector." << std::endl;
    }
return listOfPrimes[numberOfPrime];
}


void Primes::newPrimes() {
    SieveOfErastosthenes erastosthenes;
    listOfPrimes = erastosthenes.yieldPrimes(100000);
    PrimeRepository::writePrimeVectorToFile(listOfPrimes);
}