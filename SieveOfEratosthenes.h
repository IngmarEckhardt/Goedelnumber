#ifndef GOEDELNUMBER_SIEVEOFERATOSTHENES_H
#define GOEDELNUMBER_SIEVEOFERATOSTHENES_H

class Erastosthenes {

public:
    /** Yield Primes with the algorithm of Erastothenes
     * @param maxValue the value of the biggest Prime in the list
     * @return vector with the sorted primes in the range from 2 to the maxValue */
    std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue);
};

#endif //GOEDELNUMBER_SIEVEOFERATOSTHENES_H
