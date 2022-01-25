#include "PrimeRepository.h"
#include <fstream>
#include <iterator>

std::vector<unsigned long long int> PrimeRepository::readPrimesFromFile() {

    std::ifstream is(".\\primes.txt");
    std::istream_iterator<unsigned long long int> start(is), end;
    std::vector<unsigned long long int> primesFromFile(start, end);
    return primesFromFile;
}

void PrimeRepository::writePrimeVectorToFile(std::vector<unsigned long long int> &vectorToSafe) {
    std::string file = ".\\primes.txt";
    std::ofstream outFile(file);
    for (const auto &e: vectorToSafe) outFile << e << "\n";
}


