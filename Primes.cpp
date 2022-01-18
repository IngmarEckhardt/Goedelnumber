#include <filesystem>
#include <iostream>
#include "Primes.h"

Primes::Primes(bool debugflag, bool newprimes) {

    if (!loadPrimes(debugflag) || newprimes) {
        if (!getNewPrimes(debugflag) && debugflag) {

            std::cout << "No Primes loaded from file and creating Primes with Sieve of Erastothenes failed"
                      << std::endl;

        } else if (!writePrimesToFile(debugflag) && debugflag) {

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

bool Primes::loadPrimes(bool debugflag) {

    try {
        listOfPrimes = readPrimesFromFile();
    }
    catch (std::filesystem::filesystem_error const &ex) {
        if (debugflag) {
            std::cout << ex.what();
        }
        return false;
    }
    return true;
}

bool Primes::getNewPrimes(bool debugflag, unsigned long int maxValue) {

    listOfPrimes = yieldPrimes(maxValue);
    if (debugflag) {
        std::cout << listOfPrimes.size() << "Primes yielded, highest Prime has the value " << listOfPrimes.back()
                  << std::endl;
    }

    if (listOfPrimes.empty()) { return false; }
    return true;
}

bool Primes::writePrimesToFile(bool debugflag) {

    try {
        writePrimeVectorToFile(listOfPrimes);
    }
    catch (std::filesystem::filesystem_error const &ex) {
        if (debugflag) {
            std::cout << ex.what();
        }
        return false;
    }
    return true;
}

unsigned long int Primes::getPrime(unsigned int numberOfPrime, bool debugflag) {
    if (debugflag) {
        std::cout << "Serving prime" << listOfPrimes.at(numberOfPrime) << "out of Prime-Vector" << std::endl;
    }
    return listOfPrimes.at(numberOfPrime);
}