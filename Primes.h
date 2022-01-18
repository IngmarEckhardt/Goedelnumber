#ifndef GOEDELNUMBER_PRIMES_H
#define GOEDELNUMBER_PRIMES_H

#include <vector>

class Primes {

public:

    Primes(bool newprimes = false, bool debugflag = false);

    bool loadPrimes(bool debugflag);

    bool getNewPrimes(bool debugflag, unsigned long int maxValue = 100'000);

    bool writePrimesToFile(bool debugflag);

    unsigned long int getPrime(unsigned int numberOfPrime, bool debugflag);

private:
    std::vector<unsigned long long int> listOfPrimes;
};

std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue);


void writePrimeVectorToFile(std::vector<unsigned long long int> vectorToSafe);

std::vector<unsigned long long int> readPrimesFromFile();


#endif //GOEDELNUMBER_PRIMES_H
