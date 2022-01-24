#ifndef GOEDELNUMBER_PRIMES_H
#define GOEDELNUMBER_PRIMES_H

#include <vector>
#include "PrimeRepository.h"

class Primes {

public:

    explicit Primes(bool newprimes = false, bool debugflag = false);

    bool getNewPrimes(const bool &debugflag, const unsigned long int &maxValue = 100'000);

    bool loadPrimes(const bool debugflag, PrimeRepository &primeRepository);

    bool writePrimesToFile(const bool &debugflag, PrimeRepository &primeRepository);

    unsigned long int getPrime(const unsigned int &numberOfPrime, const bool &debugflag);

private:
    std::vector<unsigned long long int> listOfPrimes;
};

#endif //GOEDELNUMBER_PRIMES_H
