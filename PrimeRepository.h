#ifndef GOEDELNUMBER_PRIMEREPOSITORY_H
#define GOEDELNUMBER_PRIMEREPOSITORY_H

class PrimeRepository {

public:
    PrimeRepository ();

    void writePrimeVectorToFile(std::vector<unsigned long long int> &vectorToSafe);

    std::vector<unsigned long long int> readPrimesFromFile();
};


#endif //GOEDELNUMBER_PRIMEREPOSITORY_H
