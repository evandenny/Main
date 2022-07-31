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

#define underline "\033[4m"
#define reset "\033[0m"

std::string selection;

//MAIN MENU function
void mainmenu_select() {
    Menu::displayMainMenu();
    getline(std::cin, selection);
    if (selection == "1") {
        menuOption = MainMenu::PLAY_GAMES;
    } else if (selection == "2") {
        menuOption = MainMenu::TUTOR;
    } else if (selection == "3") {
        menuOption = MainMenu::EXIT;
    } else {
        menuOption = MainMenu::null;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
}

//GAME MENU function
void gamemenu_select() {
    getline(std::cin, selection);
    if (selection == "1") {
        gameOption = GameMenu::GUESS;
    } else if (selection == "2") {
        gameOption = GameMenu::EXIT;
    } else {
        gameOption = GameMenu::null;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
    std::cin.clear();
}

void tutormenu_select() {
    std::cout << "-> ";
    getline(std::cin, selection);
    if (selection == "1") {
        tutorOption = TutorMenu::ARRAY;
    } else if (selection == "2") {
        tutorOption = TutorMenu::EXIT;
    } else if (selection == "3") {
        Menu::exiting();
    } else {
        tutorOption = TutorMenu::null;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
        system("clear");
}

int main() {
    system("clear");
    mainmenu:
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
    myarrayt:
        tutorOption = TutorMenu::null;
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
        tutorOption = TutorMenu::null;
        goto mainmenu;
    }
    if (gameOption == GameMenu::GUESS) {
        gameOption = GameMenu::null;
        std::cout << "Starting Game... " << std::endl;
        Sleep::seconds(1);
        std::cout << "Ready!" << std::endl;
        Sleep::milliseconds(500);
        system("clear"); 
        // Game Code
        Menu::run(Guessing_Game);
        system("clear");
        goto mainmenu;
    } else if (gameOption == GameMenu::EXIT) {
        gameOption = GameMenu::null;
        goto mainmenu;
    }
    return 0;
} //CURRENT VERSION IS IN FILE 'APP'