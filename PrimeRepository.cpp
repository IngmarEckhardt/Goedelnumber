#include <fstream>
#include <iterator>
#include <filesystem>
#include "PrimeRepository.h"

void PrimeRepository::writePrimeVectorToFile(std::vector<unsigned long long int> &vectorToSafe) {
    std::ofstream outFile(".\\primes.txt");
    if (!outFile) {
        throw std::filesystem::filesystem_error("writing file failed", std::error_code());
    }
    for (const auto &e: vectorToSafe) {
        outFile << e << "\n";
    }
}

std::vector<unsigned long long int> PrimeRepository::readPrimesFromFile() {

    if (!std::filesystem::exists(".\\primes.txt")) {
        throw std::filesystem::filesystem_error("File With Primes doesn't exist", std::error_code());
    }

    std::ifstream is(".\\primes.txt");
    std::istream_iterator<unsigned long long int> start(is), end;
    std::vector<unsigned long long int> primesFromFile(start, end);

    return primesFromFile;
}

