#ifndef GOEDELNUMBER_BIGUNSIGNINT_H
#define GOEDELNUMBER_BIGUNSIGNINT_H


#include <string>

/** A class that can handle unsigned integer values that doesn't fit into a unsigned long long int */
class BigUnsignInt {

public:

    /** Constructor
     *
     * for instancing a new BigUnsignedInt that can store a number bigger than long long int in a string in reversed order
     *
     * @param number that get stored in a new BigUnsignInt-object
     * */
    explicit BigUnsignInt(unsigned long long int number = 0);


    /** *= Operator for the BigUnsignInt
     *
     * The operator take the BigUnsignInt and multiply it with a long int Value
     *
     * @param bigIntFactor the BigUnsignInt that is used and where the product is assigned after the operation
     * @param longintFactor unsigned long int right of the operator as a factor
     * */
    friend BigUnsignInt &operator*=(BigUnsignInt &bigIntFactor, const unsigned long int &longintFactor);


    /** Print the BigInt with Output-Stream
     *
     * The Operator can send the BigUnsignInt in the correct order (unreversed) in a Output-Stream
     *
     * @param out the Outputstream left of the operator
     * @param numberToPrint the BigUnsignInt that will be placed in the Output-Stream
     * */
    friend std::ostream &operator<<(std::ostream &out,const BigUnsignInt &numberToPrint);

    /** checks if the object is empty
     *
     * @return false if the BigInt is empty, has the Ascii-Sign '0' as first sign or the Number '0' as a single digit,
     *          true for every other case */
    bool isEmpty();

private:
    /// Storage of the reversed number
    std::string digits;
};

#endif //GOEDELNUMBER_BIGUNSIGNINT_H