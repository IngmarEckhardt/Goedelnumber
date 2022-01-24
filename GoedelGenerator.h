#ifndef GOEDELNUMBER_GOEDELGENERATOR_H
#define GOEDELNUMBER_GOEDELGENERATOR_H

#include "Primes.h"
#include "BigUnsignInt.h"
#include <string>


class GoedelGenerator {

public:
    /** Constructor
     *
     * @param newprimes set to true with Commandline Argument to create a new file with prime-numbers instead of
     *                  using the existing file
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen */
    explicit GoedelGenerator(bool newprimes = false, bool debugflag = false);

    /** The Generator-Object ask for User-Input and save the formula in the private string variable formula. Return the
     * formula for the purpose of implementing Unit-Tests in further development.
     *
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
     * @return the formula as a std::string */
    std::string getFormulaFromUser(bool &debugflag);

    BigUnsignInt calculateGoedelNumber(bool &debugflag);

    bool printCalculatedNumberToScreen(bool &debugflag);

private:
    BigUnsignInt goedelnumber;
    std::string formula;
    Primes primes;
};


#endif //GOEDELNUMBER_GOEDELGENERATOR_H