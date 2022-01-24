#include <iostream>
#include "GoedelGenerator.h"

bool isCorrectFormula(std::string &formulaToCheck, bool &debugflag);

std::vector<unsigned long long int> encodeFormula(std::string &formulaToEncode, bool &debugflag);

unsigned long long int intPow (unsigned long long int base, unsigned short int exp);


GoedelGenerator::GoedelGenerator(bool newprimes, bool debugflag) {
    formula = "";
    goedelnumber = BigUnsignInt(0);
    primes = Primes(newprimes,debugflag);
}

std::string GoedelGenerator::getFormulaFromUser(bool &debugflag) {
    std::string formulaToCheck;
    bool exit = false;

    do {
        std::cout << "Geben Sie die Formel ein deren Gödelnummer berechnet werden soll:\n"
                     "(Hinweise zum Format auf der Hilfeseite. Abbrechen mit Enter ohne Eingabe)" << std::endl;
        std::cin >> formulaToCheck;
        if (formulaToCheck.empty()) {exit = true;}
    } while (!exit || !isCorrectFormula(formulaToCheck,debugflag));
    formula = formulaToCheck;
    return formula;
}


BigUnsignInt GoedelGenerator::calculateGoedelNumber(bool &debugflag) {
    std::vector<unsigned long long int> encodedFormula = encodeFormula(formula, debugflag);

    if (encodedFormula.empty()) {
        if (debugflag) {
            std::cout << "Couldn't calculate a Goedelnumber because encodedFormula was empty" << std::endl;
        }
        return goedelnumber;
    }
    else {
        goedelnumber = BigUnsignInt(1);
        for (int i = 0; i < encodedFormula.size()-1; i++)
            goedelnumber *= (intPow(primes.getPrime(i,debugflag),encodedFormula[i]));
    }
    return goedelnumber;
}


bool GoedelGenerator::printCalculatedNumberToScreen(bool &debugflag) {
    if (goedelnumber.isEmpty()) {
        if (debugflag) {
            std::cout << "Couldn't print Goedelnumber because it was empty" << std::endl;
        }
        return false;}
    else {
        std::cout << "Die Gödelnummer der Formel: " << formula << " ist " << goedelnumber << std::endl;
    }
    return false;
}

bool isCorrectFormula(std::string &formulaToCheck, bool &debugflag) {
    for (int i = 0; i < formulaToCheck.size()-1; i++) {
        if (formulaToCheck[i] == '+' || formulaToCheck[i] == '-' || formulaToCheck[i] == '*' || formulaToCheck[i] == '/'
        || formulaToCheck[i] == '=' || formulaToCheck[i] == 's' || formulaToCheck[i] == '0' || formulaToCheck[i] == 'a' || formulaToCheck[i] == 'b'
            || formulaToCheck[i] == 'c' || formulaToCheck[i] == 'd' || formulaToCheck[i] == 'e' || formulaToCheck[i] == 'f') {continue;}
        else {return false;}
    }
    return true;
}


std::vector<unsigned long long int> encodeFormula(std::string &formulaToEncode, bool &debugflag){
    std::vector<unsigned long long int> encodedFormula(formulaToEncode.size());

    if (formulaToEncode.empty()) {
        if (debugflag) {std::cout << "Unable to encode, formula was empty." << std::endl;}
        return encodedFormula;
    }
    else {
        for (int i = 0; i < formulaToEncode.size()-1; i++) {
            if (formulaToEncode[i] == '+') {encodedFormula[i] = 1;}
            else if (formulaToEncode[i] == '-') {encodedFormula[i] = 2;}
            else if (formulaToEncode[i] == '*') {encodedFormula[i] = 3;}
            else if (formulaToEncode[i] == '/') {encodedFormula[i] = 4;}
            else if (formulaToEncode[i] == '=') {encodedFormula[i] = 5;}
            else if (formulaToEncode[i] == '0') {encodedFormula[i] = 6;}
            else if (formulaToEncode[i] == 's') {encodedFormula[i] = 7;}
            else if (formulaToEncode[i] == 'a') {encodedFormula[i] = 8;}
            else if (formulaToEncode[i] == 'b') {encodedFormula[i] = 9;}
            else if (formulaToEncode[i] == 'c') {encodedFormula[i] = 10;}
            else if (formulaToEncode[i] == 'd') {encodedFormula[i] = 11;}
            else if (formulaToEncode[i] == 'e') {encodedFormula[i] = 12;}
            else if (formulaToEncode[i] == 'f') {encodedFormula[i] = 13;}
        }
    }
    return encodedFormula;
}


unsigned long long int intPow (unsigned long long int base, unsigned short int exp) {
    unsigned long long int result = base;

    if (exp == 1) {
        return result;
    }
    else {
        result *= intPow(base, exp-1);
    }

    return result;
}