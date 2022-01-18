#include "GoedelGenerator.h"

GoedelGenerator::GoedelGenerator(bool newprimes, bool debugflag) {
    formula = "empty";
    goedelnumber = 0;
    primes = new Primes (newprimes,debugflag);

}

std::string GoedelGenerator::getFormulaFromUser(bool debugflag) {

    return formula;
}

unsigned long long int GoedelGenerator::calculateGoedelNumber(bool debugflag) {
    primes.getNewPrimes(debugflag);
    return goedelnumber;
}

bool GoedelGenerator::printCalculatedNumberToScreen(bool debugflag) {
    return false;
}
