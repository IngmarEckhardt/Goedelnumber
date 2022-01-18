#include "connector.h"
#include "HelpPage.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void Menu(bool newprimes, bool debug);

int main(int argc, char *argv[]) {

    std::string argument1 = "empty";
    std::string argument2 = "empty";
    bool newPrimes = false;
    bool debug = false;

    if (argc > 1) {
        argument1 = std::string(argv[1]);
    }
    if (argc > 2) {
        argument2 = std::string(argv[2]);
    }
    if (argument1 == "np" || argument2 == "np") { newPrimes = true; }
    if (argument1 == "debug" || argument2 == "debug") { debug = true; }

    Menu(newPrimes, debug);
}


void Menu(bool newprimes, bool debug) {

    std::string input;
    unsigned long int menu;
    bool exit = false;

    while (!exit) {
        cout << "\n" << setw(27) << "Menü\n";
        cout << setw(51) << "Gödelnummer (1)\n";
        cout << setw(50) << "Hilfe und Kontakt (2)\n";
        cout << setw(50) << "Programm beenden (0)\n" << endl;

        cin >> input;

        try {
            menu = std::stoul(input);

        } catch (const std::exception &e) {

            if (debug) { cout << &e << endl; }
            cout << "Bitte geben Sie ausschließlich ganze Zahlen ein" << endl;
            continue;
        }

        if (menu > 2) {
            cout << "Bitte wählen Sie ausschließlich vorhandene Menüpunkte aus" << endl;
            continue;
        }

        switch (menu) {
            case 1:
                goedel::goedelmain(newprimes, debug);
                break;

            case 2:
                cout << helpText << std::endl;
                break;

            case 0:
                exit = true;
                break;

            default:;
        }
    }
}