#include "Primes.h"
#include "SieveOfEratosthenes.h"
#include <iostream>

Primes::Primes(bool newprimes, bool debugflag) {
    PrimeRepository primeRepository;
    if (newprimes) {
        newPrimes(primeRepository);
    } else {
        listOfPrimes = primeRepository.readPrimesFromFile();
        if (listOfPrimes.empty()) {
            newPrimes(primeRepository);
        }
    }
}


unsigned long int Primes::getPrime(const unsigned int &numberOfPrime, const bool &debugflag) {
    if (debugflag) {
    std::cout << "Serving prime" << listOfPrimes.at(numberOfPrime) << "out of Prime-Vector" << std::endl;}

return listOfPrimes.at(numberOfPrime);
}


void Primes::newPrimes(PrimeRepository &primeRepository) {
    Erastosthenes erastosthenes;
    listOfPrimes = erastosthenes.yieldPrimes(100.000);
    primeRepository.writePrimeVectorToFile(listOfPrimes);
}