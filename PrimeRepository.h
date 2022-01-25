#ifndef GOEDELNUMBER_PRIMEREPOSITORY_H
#define GOEDELNUMBER_PRIMEREPOSITORY_H


#include <vector>

class PrimeRepository {

public:

    void writePrimeVectorToFile(std::vector<unsigned long long int> &vectorToSafe);

    static std::vector<unsigned long long int> readPrimesFromFile();
};


#endif //GOEDELNUMBER_PRIMEREPOSITORY_H
