#ifndef GOEDELNUMBER_PRIMES_H
#define GOEDELNUMBER_PRIMES_H

#include <vector>
#include "PrimeRepository.h"

class Primes {

public:

    explicit Primes(bool newprimes = false, bool debugflag = false);

    unsigned long int getPrime(const unsigned int &numberOfPrime, const bool &debugflag);

private:
    std::vector<unsigned long long int> listOfPrimes;

    void newPrimes(PrimeRepository &primeRepository);
};

#endif //GOEDELNUMBER_PRIMES_H
