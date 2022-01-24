#ifndef GOEDELNUMBER_BIGUNSIGNINT_H
#define GOEDELNUMBER_BIGUNSIGNINT_H


#include <string>

class BigUnsignInt {


public:

    //Constructor
    BigUnsignInt(unsigned long long int number = 0);

    /** Multiply the BigInt with the next factor*/
    friend BigUnsignInt &operator*=(BigUnsignInt &bigIntFactor, const unsigned long int &longintFactor);

    /** Print the BigInt with Output-Stream */
    friend std::ostream &operator<<(std::ostream &out,const BigUnsignInt &numberToPrint);

    /**
     * @return false if the BigInt is empty or '0' as a single digit*/
    bool isEmpty();

private:
    std::string digits;
};


#endif //GOEDELNUMBER_BIGUNSIGNINT_H
