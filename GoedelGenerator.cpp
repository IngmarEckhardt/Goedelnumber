#include <iostream>
#include "GoedelGenerator.h"

bool isCorrectFormula(const std::string &formulaToCheck);



unsigned long long int intPow(unsigned long long int base, unsigned short int exp);


GoedelGenerator::GoedelGenerator(bool newprimes) {
    formula = "";
    goedelnumber = BigUnsignInt();
    primes = Primes(newprimes);
}

std::string GoedelGenerator::getFormulaFromUser(bool &debugflag) {
    std::string formulaToCheck;

    do {

        std::cout << "Geben Sie die Formel ein deren Goedelnummer berechnet werden soll:\n"
                     "(Hinweise zum Format auf der Hilfeseite. Abbrechen mit Enter ohne Eingabe)" << std::endl;
        std::getline(std::cin, formulaToCheck);

        if (formulaToCheck.empty()) { break; }

    } while (!isCorrectFormula(formulaToCheck));
    formula = formulaToCheck;
    return formula;
}


BigUnsignInt GoedelGenerator::calculateGoedelNumber(bool &debugflag) {
    std::vector<unsigned short int> encodedFormula = encodeFormula(formula, debugflag);

    if (encodedFormula.empty()) {
        if (debugflag) {
            std::cout << "Couldn't calculate a Goedelnumber because encodedFormula was empty" << std::endl;
        }
        return goedelnumber;
    } else {
        goedelnumber = BigUnsignInt(1);
        for (int i = 0; i < encodedFormula.size(); i++) {
            goedelnumber *= (intPow(primes.getPrime(i), encodedFormula[i]));
        }
        return goedelnumber;
    }
}


bool GoedelGenerator::printCalculatedNumberToScreen(bool &debugflag) {
    if (goedelnumber.isEmpty()) {
        if (debugflag) {
            std::cout << "Couldn't print Goedelnumber because it was empty" << std::endl;
        }
        return false;
    } else {
        std::cout << "Die Gödelnummer der Formel \" " << formula << " \" ist: " << goedelnumber << std::endl;
    }
    return true;
}

bool GoedelGenerator::isCorrectFormula(const std::string &formulaToCheck) {

    for (const char i: formulaToCheck) {
        if (i == '+' || i == '-' || i == '*' || i == '/' || i == '=' || i == 's' || i == '0' || i == 'a' || i == 'b' ||
            i == 'c' || i == 'd' || i == 'e' || i == 'f') {
            continue;
        } else {
            std::cout << "Die Eingabe entsprach keiner korrekten Formel" << std::endl;
            return false;
        }
    }
    return true;
}


std::vector<unsigned short int>  GoedelGenerator::encodeFormula(std::string &formulaToEncode, bool &debugflag) {

    std::vector<unsigned short int> encodedFormula(formulaToEncode.size());

    if (formulaToEncode.empty()) {
        if (debugflag) {
            std::cout << "Unable to encode, formula was empty." << std::endl;
        }
        return encodedFormula;
    } else {
        for (int i = 0; i < formulaToEncode.size(); i++) {
            if (formulaToEncode[i] == '+') { encodedFormula[i] = 1; }
            else if (formulaToEncode[i] == '-') { encodedFormula[i] = 2; }
            else if (formulaToEncode[i] == '*') { encodedFormula[i] = 3; }
            else if (formulaToEncode[i] == '/') { encodedFormula[i] = 4; }
            else if (formulaToEncode[i] == '=') { encodedFormula[i] = 5; }
            else if (formulaToEncode[i] == '0') { encodedFormula[i] = 6; }
            else if (formulaToEncode[i] == 's') { encodedFormula[i] = 7; }
            else if (formulaToEncode[i] == 'a') { encodedFormula[i] = 8; }
            else if (formulaToEncode[i] == 'b') { encodedFormula[i] = 9; }
            else if (formulaToEncode[i] == 'c') { encodedFormula[i] = 10; }
            else if (formulaToEncode[i] == 'd') { encodedFormula[i] = 11; }
            else if (formulaToEncode[i] == 'e') { encodedFormula[i] = 12; }
            else if (formulaToEncode[i] == 'f') { encodedFormula[i] = 13; }
        }
    }
    return encodedFormula;
}


unsigned long long int GoedelGenerator::intPow(unsigned long long int base, unsigned short int exp) {

    unsigned long long int result = base;
    if (exp == 1) {
        return result;
    } else {
        result *= intPow(base, exp - 1);
    }

    return result;
}