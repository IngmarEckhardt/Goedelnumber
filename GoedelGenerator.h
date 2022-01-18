#ifndef GOEDELNUMBER_GOEDELGENERATOR_H
#define GOEDELNUMBER_GOEDELGENERATOR_H

#include <string>
#include "Primes.h"


class GoedelGenerator {

public:

    explicit GoedelGenerator(bool newprimes = false, bool debugflag = false);

    std::string getFormulaFromUser(bool debugflag);

    unsigned long long int calculateGoedelNumber(bool debugflag);

    bool printCalculatedNumberToScreen(bool debugflag);

private:
    unsigned long long int goedelnumber;
    std::string formula;
    Primes primes;
};


#endif //GOEDELNUMBER_GOEDELGENERATOR_H