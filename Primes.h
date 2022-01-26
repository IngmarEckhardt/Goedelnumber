#ifndef GOEDELNUMBER_PRIMES_H
#define GOEDELNUMBER_PRIMES_H

#include <vector>


class Primes {

public:

    explicit Primes(bool newprimes = false);

    unsigned long int getPrime(unsigned int numberOfPrime);

private:
    std::vector<unsigned long long int> listOfPrimes;

    void newPrimes();
};

#endif //GOEDELNUMBER_PRIMES_H
