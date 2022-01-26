#ifndef GOEDELNUMBER_PRIMES_H
#define GOEDELNUMBER_PRIMES_H

#include <vector>


class Primes {

public:
    /**
     * Constructor
     *
     *  Uses PrimeRepository to load prime numbers from a file and storem them into listOfPrimes, and if it fails or if
     *  the newprimes-flag is set it uses newPrimes(); to create a new list of primes and save them with the
     *  PrimeRepository in a new file.
     *
     * @param newprimes set to true with Commandline Argument to create a new file with prime-numbers instead of
     *                  using the existing file
     * */
    explicit Primes(bool newprimes = false);

    /**
     * Serving single prime numbers
     *
     * It serves prime numbers out of the list
     *
     * @param numberOfPrime the prime-number that should be returned
     * @param debugflag set to true with Commandline Argument to print the Prime-Numbers to Screen
     * @return the prime numbers starting with number 2
     * */
    unsigned long int getPrime(unsigned int numberOfPrime, bool &debugflag);

private:
    /**
     * Creating a new list of primes
     *
     * It uses the algorithm SieveOfEratosthenes (.h/.cpp) to yield the prime numbers up to the value of 100.000, store
     * them into listOfPrimes and uses PrimeRepository to save it into a primes.txt
     * */
    void newPrimes();

    /// Storage of the primes
    std::vector<unsigned long long int> listOfPrimes;
};

#endif //GOEDELNUMBER_PRIMES_H
