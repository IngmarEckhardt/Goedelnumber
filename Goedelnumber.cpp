#include "GoedelGenerator.h"
#include "HelpPage.h"
#include <iostream>
#include <iomanip>

/**
 * Parse the Commandline-Arguments
 *
 * It parses Commandline Arguments if the user use -np or -debug as Argument, and then set the bool-variables to true.
 *
 * @param argc - the Commmandline Argument Counter
 * @param argv - the Commandline Argument Vector
 * @param newPrimes the Bool will be set to true if Argument '-np' is used
 * @param debugflag the Bool will be set to true if Argument '-debug' is used
 * */
void parseCommandLineArgs(int argc, char *const *argv, bool &newPrimes, bool &debugflag);

/** Entry Point Menu
 *
 * Ask for UserInput in the Menu, check the Input and uses HelpPage.h/.cpp to print a informative text to the screen or
 * calls goedelControl() to start the core program logic.
 *
 * @param newprimes set to true with Commandline Argument to create a new file with prime-numbers instead of
 *                  using the existing file in further functions
 * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
 * */
void Menu(bool newprimes, bool debugflag);

/**
 * Controller for core program logic
 *
 * instantiate a instance of the GoedelGenerator.h and uses its class-functions getFormulaFromUser, calculateGoedelnumber,
 * and printCalculatedNumberToScreen() to control the flow of the core program logic.
 *
 * @param newprimes set to true with Commandline Argument to create a new file with prime-numbers instead of
 *                  using the existing file in further functions
 * @param debugflag set to true with Commandline Argument to print Error-Messages to Screen
 * */
void goedelControl(bool newprimes, bool debugflag);



/**
 * Main-Function
 *
 * initiate the parsing of the CommandLine-Arguments with parseCommandLineArgs() and start the Menu()-Funktion
 *
 * @param argc the argument counter that is served from the Operating System
 * @param argv the argument Vector that is served from the Operating System
 * */
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
    unsigned short int menu;
    bool exit = false;

    // loop that leads the user back to the menu until the exit-Menu Option is called from User
    while (!exit) {

        if (debugflag){
            std::cout << "\nDebugflag is set" << std::endl;
            if (newprimes) {
                std::cout << "NewPrimes-flag is set\n" << std::endl;
            }
        }

        std::cout << std::setw(27) << "Menue\n\n";
        std::cout << std::setw(50) << "Berechne eine Goedelnummer (1)\n";
        std::cout << std::setw(50) << "Hilfe und Kontakt (2)\n";
        std::cout << std::setw(50) << "Programm beenden (0)\n" << std::endl;

        std::getline(std::cin,input);

        try {
            menu = std::stoul(input);

        } catch (const std::exception &e) {

            if (debugflag) {
                std::cout << &e << std::endl;
            }
            std::cout << "Bitte geben Sie ausschliesslich ganze Zahlen ein" << std::endl;
            continue;
        }

        if (menu > 2) {
            std::cout << "Bitte waehlen Sie ausschliesslich vorhandene Menuepunkte aus" << std::endl;
            continue;
        }

        switch (menu) {
            case 1:
                goedelControl(newprimes, debugflag);
                break;

            case 2:
                std::cout << helpText() << std::endl;
                break;

            case 0:
                exit = true;
                break;

            default:;
        }
    }
}

void goedelControl(bool newprimes, bool debugflag) {

    GoedelGenerator goedelGenerator (newprimes);

    goedelGenerator.getFormulaFromUser(debugflag);

    goedelGenerator.calculateGoedelNumber(debugflag);

    goedelGenerator.printCalculatedNumberToScreen(debugflag);

}