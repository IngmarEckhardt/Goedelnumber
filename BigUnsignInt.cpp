#include "BigUnsignInt.h"
#include <vector>
#include <iostream>

BigUnsignInt::BigUnsignInt(unsigned long long int number){
    do{
        digits.push_back(number % 10);
        number /= 10;
    } while (number);
}

BigUnsignInt &operator*=(BigUnsignInt &bigIntFactor, const unsigned long int &longIntFactor) {

    BigUnsignInt interimBigInt(longIntFactor);

    unsigned short int n = bigIntFactor.digits.size();
    unsigned short int m = interimBigInt.digits.size();
    std::vector<unsigned short int> interimProduct(n + m, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            interimProduct[i + j] += (bigIntFactor.digits[i]) * (interimBigInt.digits[j]);
        }

    bigIntFactor.digits.resize(interimProduct.size());
    for (unsigned short int s, i = 0, t = 0; i < interimProduct.size(); i++) {
        s = t + interimProduct[i];
        interimProduct[i] = s % 10;
        t = s / 10;
        bigIntFactor.digits[i] = interimProduct[i];
    }

    for (int i = interimProduct.size() - 1; i >= 1 && !interimProduct[i]; i--) {
        bigIntFactor.digits.pop_back();
    }

    return bigIntFactor;
}
std::ostream &operator<<(std::ostream &out,const BigUnsignInt &numberToPrint){
    for (int i = numberToPrint.digits.size() - 1; i >= 0; i--) {
        std::cout << (unsigned short int)numberToPrint.digits[i];}
    return std::cout;
}

bool BigUnsignInt::isEmpty() {
    if (digits.empty() || (digits.size()==1 && digits[0] == 0)) {return true;}
    return false;
}