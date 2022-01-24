#include "GoedelGenerator.h"
#include "HelpPage.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void parseCommandLineArgs(int argc, char *const *argv, bool &newPrimes, bool &debugflag);
void Menu(bool newprimes, bool debugflag);
void goedelControl(bool newprimes, bool debugflag);


int main(int argc, char *argv[]) {

    bool newPrimes = false;
    bool debugflag = false;

    parseCommandLineArgs(argc, argv, newPrimes, debugflag);

    Menu(newPrimes, debugflag);
}

void parseCommandLineArgs(int argc, char *const *argv, bool &newPrimes, bool &debugflag) {
    std::string argument1 = "";
    std::string argument2 = "";
    if (argc > 1) {
        argument1 = std::string(argv[1]);
    }
    if (argc > 2) {
        argument2 = std::string(argv[2]);
    }
    if (argument1 == "-np" || argument2 == "-np") { newPrimes = true; }
    if (argument1 == "-debug" || argument2 == "-debug") { debugflag = true; }
}


void Menu(bool newprimes, bool debugflag) {

    std::string input;
    unsigned long int menu;
    bool exit = false;

    while (!exit) {
        cout << "\n" << setw(27) << "Menü\n";
        cout << setw(51) << "Berechne eine Gödelnummer (1)\n";
        cout << setw(50) << "Hilfe und Kontakt (2)\n";
        cout << setw(50) << "Programm beenden (0)\n" << endl;

        cin >> input;

        try {
            menu = std::stoul(input);

        } catch (const std::exception &e) {

            if (debugflag) {
                cout << &e << endl;
            }
            cout << "Bitte geben Sie ausschließlich ganze Zahlen ein" << endl;
            continue;
        }

        if (menu > 2) {
            cout << "Bitte wählen Sie ausschließlich vorhandene Menüpunkte aus" << endl;
            continue;
        }

        switch (menu) {
            case 1:
                goedelControl(newprimes, debugflag);
                break;

            case 2:
                cout << helpText() << std::endl;
                break;

            case 0:
                exit = true;
                break;

            default:;
        }
    }
}

void goedelControl(bool newprimes, bool debugflag) {

    GoedelGenerator goedelGenerator (newprimes, debugflag);

    goedelGenerator.getFormulaFromUser(debugflag);

    goedelGenerator.calculateGoedelNumber(debugflag);

    goedelGenerator.printCalculatedNumberToScreen(debugflag);

}