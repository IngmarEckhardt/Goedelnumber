#ifndef GOEDELNUMBER_PRIMEREPOSITORY_H
#define GOEDELNUMBER_PRIMEREPOSITORY_H


#include <vector>

/** Class that manage the storage of prime-numbers in a file */
class PrimeRepository {

public:
    /** Function that load primes from a file
     *
     * The function load the prime out of a primes.txt-file that is placed in the folder where the program ist started
     * and store them in a vector-object.
     *
     * @return a unsigned long long int-std::vector with all primes from the file sorted from smallest prime (2) until
     *          the highest prime that is stored in the file
     * */
    static std::vector<unsigned long long int> readPrimesFromFile();

    /** Store a Vector with Primes to a File
     *
     * Function will save the primes in a primes.txt-File in the same folder where the program is started. Maximum size
     * of the file depends on the Operating System where the program is running.
     *
     * @param vectorToSafe the Vector with primes that should get saved
     */
    static void writePrimeVectorToFile(std::vector<unsigned long long int> &vectorToSafe);
};


#endif //GOEDELNUMBER_PRIMEREPOSITORY_H
