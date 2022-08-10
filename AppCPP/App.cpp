#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include <limits>
#include "Sleep.h"
#include "ArrayTutorial.h"
#include "menu.h"
#include "Guess.h"
#include "hangman.h"

#define underline "\033[4m"
#define reset "\033[0m"

std::string selection;
//MAIN MENU function
void mainmenu_select() {
    Menu::displayMainMenu();
    getline(std::cin, selection);
    if (selection == "1") {
        mainPLAY;
    } else if (selection == "2") {
        mainTUTOR;
    } else if (selection == "3") {
        mainEXIT;
    } else {
        mainNull;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
}

//GAME MENU function
void gamemenu_select() {
    getline(std::cin, selection);
    if (selection == "1") {
        gameGUESS;
    } else if (selection == "2") {
        gameHANGMAN;
    } else if (selection == "3") {
        gameEXIT;
    } else {
        gameNull;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
    std::cin.clear();
}

void tutormenu_select() {
    std::cout << "-> ";
    getline(std::cin, selection);
    if (selection == "1") {
        tutorARRAY;
    } else if (selection == "2") {
        tutorEXIT;
    } else if (selection == "3") {
        Menu::exiting();
    } else {
        tutorNull;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
        system("clear");
}

int main() {
    do {
    system("clear");
    Menu::switchMain();
    if (menuOption == MainMenu::PLAY_GAMES) {
        system("clear");
        Menu::switchGame();
    } else if (menuOption == MainMenu::TUTOR) {
        system("clear");
        Menu::switchTutor();        
    } else if (menuOption == MainMenu::EXIT) {
        Menu::exiting();
    }
    if (tutorOption == TutorMenu::ARRAY) {
        tutorNull;
        std::cout << "Starting Array Tutorial..." << std::endl;
        Sleep::milliseconds(300);
        std::cout << "Ready!" << std::endl;
        Sleep::milliseconds(400);
        system("clear");
        // Tutorial Code
        Menu::run(ArrayTutorial);
        system("clear");
        Menu::switchEndOfTutor();
    } else if (tutorOption == TutorMenu::EXIT) {
        tutorNull;
    }
    if (gameOption == GameMenu::GUESS) {
        gameNull;
        std::cout << "Starting Game... " << std::endl;
        Sleep::seconds(1);
        std::cout << "Ready!" << std::endl;
        Sleep::milliseconds(500);
        do {
        system("clear"); 
        // Game Code
        Menu::run(Guessing_Game);
        std::cin.clear();
        system("clear");
        Menu::switchEndOfGame();
        } while (endOfGameOption == endOfGameMenu::PLAY_AGAIN);
    } else if (gameOption == GameMenu::HANGMAN) {
        gameNull;
        system("clear");
        Sleep::milliseconds(200);
        std::cout << "Starting Game... " << std::endl;
        Sleep::milliseconds(500);
        std::cout << "Ready!" << std::endl;
        Sleep::milliseconds(500);
        do {
        system("clear");
        // Game Code
        Menu::run(HANGMAN::game);
        std::cin.clear();
        Menu::switchEndOfGame();
        } while (endOfGameOption == endOfGameMenu::PLAY_AGAIN); 
    } else if (gameOption == GameMenu::EXIT) {
        gameEXIT;
    }
    } while (menuOption != MainMenu::EXIT || gameOption != GameMenu::EXIT || tutorOption != TutorMenu::EXIT);
    system("clear");
    Sleep::milliseconds(500);
    std::cout << "Exiting..." << std::endl;
    Sleep::milliseconds(800);
    system("clear");
    return 0;
} //CURRENT VERSION IS IN FILE 'APP'