#include <cmath>
#include <vector>
#include "SieveOfEratosthenes.h"


std::vector<unsigned long long int> Erastosthenes::yieldPrimes(unsigned long long int maxValue) {

    size_t size{maxValue};
    std::vector<unsigned long long int> listOfPrimes;
    //Ein Bitvector mit der Größe der höchsten gewünschten Primzahl wird erzeugt und alle Bits auf True gesetzt
    std::vector<bool> bitVector(size);
    std::fill(bitVector.begin(), bitVector.end(), true);

    bitVector[0] = false;
    bitVector[1] = false;

    // Nachdem von Hand die Position 0 und 1 auf false genommen wurde, setzt der Algorythmus der als Sieb des Eratosthenes
    // bekannt ist, alle weiteren Indexpositionen im Bitvector, welche keine Primzahlen sind, ebenfalls auf false, indem er
    // alle Produkte einer Primzahl aus der Liste löscht.

    const unsigned long long int rangeOne = sqrt(size) + 1;
    for (unsigned long int i = 2; i < rangeOne; i++) {

        //Ist eine Indexposition schon auf false gesetzt, entspricht sie dem vielfachen einer vorher identifizierten Primzahl
        if (!bitVector[i]) continue;

        //Ist die Indexposition true beginnt der Algorythmus alle Produkte dieser Zahl bis zum Ende des Vektors auf false zu setzen
        unsigned long int rangeTwo = (size - 1) / i + 1;
        for (unsigned long int j = 2; j < rangeTwo; j++) {
            bitVector[i * j] = false;
        }
    }

    //Die Indexpositionen welche nach dem Sieben noch auf true stehen werden als Primzahlen in einem weiteren Vektor gespeichert.
    for (unsigned long long int k = 2; k < size; k++) {
        if (bitVector[k]) {
            listOfPrimes.push_back(k);
        }
    }
    return listOfPrimes;
}