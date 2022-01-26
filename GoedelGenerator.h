#ifndef GOEDELNUMBER_GOEDELGENERATOR_H
#define GOEDELNUMBER_GOEDELGENERATOR_H

#include "Primes.h"
#include "BigUnsignInt.h"
#include <string>


class GoedelGenerator {

public:
    /** Constructor
     *
     * declare the member-variables and the instantiation of the Primes-Class-Object that initiate and manage the access
     * to the file with prime-numbers.
     *
     * @param newprimes set to true with Commandline Argument to create a new file with prime-numbers instead of
     *                  using the existing file
     * */
    explicit GoedelGenerator(bool newprimes = false);

    /**
     * Managing the User-Input
     *
     * The Generator-Object ask for User-Input and save the formula in the private string variable formula. Uses the
     * function isCorrectFormula(string) to check the UserInput.
     *
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
     * @return the formula as a std::string for the purpose of Unit-Tests
     * */
    std::string getFormulaFromUser(bool &debugflag);

    /**
     * Calculation of the Goedelnumber
     *
     * Core-functionality. The function use encodeFormula() to encode the user-input to a vector of numbers and then use the function
     * Primes::getPrime(int) and the function intPow(int base, int exp) to calculate the Goedelnumber and store it into
     * a BigUnsignInt-Object.
     *
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
     * @return the BigUnsignInt-Object with the Goedelnumber for the purpose of Unit-Tests
     * */
    BigUnsignInt calculateGoedelNumber(bool &debugflag);


    /** Print the result to the Screen
     *
     * Function will print the result to the screen if the formula is not empty.
     *
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
     * @return false if the formula was empty, true for every other case for the purpose of Unit-Tests
     * */
    bool printCalculatedNumberToScreen(bool &debugflag);

private:
    /** Checking the formula for correctness
     *
     * Function will check if the User-Input contain only allowed symbols (see Help-Text)
     *
     * @param formulaToCheck the String with the User-Input
     * @return true if the string contain only allowed symbols, false for the other case
     * */
    bool isCorrectFormula(const std::string &formulaToCheck);

    /**
     * Encode the User-Input
     *
     * Encode the user-Input into numbers for later use in the calculation and store them in a Vector-Object
     *
     * @param formulaToEncode the User-Input that should get encoded
     * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
     *
     * @return the encoded Formula as a std::vector
     * */
    std::vector<unsigned short int> encodeFormula(std::string &formulaToEncode, bool &debugflag);

    /** potentiate Int-Numbers
     *
     * A Function that calculate the result of the power with a integer base and integer exponent, because it isn't
     * implemented in the c++ standard-library.
     *
     * @param base the base-integer value
     * @param exp the exponent-integer value
     * @return the result of the calculation
     * */
    unsigned long long int intPow(unsigned long long int base, unsigned short int exp);

    ///stores the Goedelnumber in a BigUnsignInt-Object
    BigUnsignInt goedelnumber;
    ///stores the UserInput in a string
    std::string formula;
    /// stores a instance of a Primes-Class-Object.
    Primes primes;
};


#endif //GOEDELNUMBER_GOEDELGENERATOR_H