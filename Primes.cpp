#include "Primes.h"
#include "SieveOfEratosthenes.h"
#include <filesystem>
#include <iostream>

Primes::Primes(bool debugflag, bool newprimes) {
    PrimeRepository primeRepository;

    if (!loadPrimes(debugflag, primeRepository) || newprimes) {
        if (!getNewPrimes(debugflag) && debugflag) {

            std::cout << "No Primes loaded from file and creating Primes with Sieve of Erastothenes failed"
                      << std::endl;

        } else if (!writePrimesToFile(debugflag,primeRepository) && debugflag) {

            std::cout << "No Primes loaded from file, created new list of Primes,"
                         " but couldn't write a new file of Primes" << std::endl;
        } else if (debugflag) {
            std::cout << "Couldn't load Primes from file, created sucessfully new list of primes and a new file."
                      << std::endl;
        }
    } else if (debugflag) {
        std::cout << "Loaded sucessfully Primes from file" << std::endl;
    }
}

bool Primes::getNewPrimes(const bool &debugflag, const unsigned long int &maxValue) {
    Erastosthenes erastosthenes;

    listOfPrimes = erastosthenes.yieldPrimes(maxValue);
    if (debugflag) {
        std::cout << listOfPrimes.size() << "Primes yielded, highest Prime has the value " << listOfPrimes.back()
                  << std::endl;
    }

    if (listOfPrimes.empty()) { return false; }
    return true;
}

bool Primes::loadPrimes(const bool debugflag, PrimeRepository &primeRepository) {

    try {
        listOfPrimes = primeRepository.readPrimesFromFile();
    }
    catch (std::filesystem::filesystem_error const &ex) {
        if (debugflag) {
            std::cout << ex.what();
        }
        return false;
    }
    return true;
}

bool Primes::writePrimesToFile(const bool &debugflag, PrimeRepository &primeRepository) {

    try {
        primeRepository.writePrimeVectorToFile(listOfPrimes);
    }
    catch (std::filesystem::filesystem_error const &ex) {
        if (debugflag) {
            std::cout << ex.what();
        }
        return false;
    }
    return true;
}


unsigned long int Primes::getPrime(const unsigned int &numberOfPrime, const bool &debugflag) {
    if (debugflag) {
        std::cout << "Serving prime" << listOfPrimes.at(numberOfPrime) << "out of Prime-Vector" << std::endl;
    }
    return listOfPrimes.at(numberOfPrime);
}

