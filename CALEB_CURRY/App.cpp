#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include "Sleep.h"
#include "ArrayTutorial.h"
#include "menu.h"
#include "Guess.h"

#define underline "\033[4m"
#define reset "\033[0m"

std::string selection;
MainMenu menuOption = MainMenu::null;
GameMenu gameOption = GameMenu::null;
TutorMenu tutorOption = TutorMenu::null;

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
    std::cout << "-> ";
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
    do {
        mainmenu_select();
        system("clear");
    } while (menuOption == MainMenu::null);
    if (menuOption == MainMenu::PLAY_GAMES) {
        system("clear");
        do
        {
            std::cout << "Please select a game to play:" << std::endl;
            std::cout << "1. Guessing Game" << std::endl;
            std::cout << "2. Exit to Main Menu" << std::endl;
            gamemenu_select();
            system("clear");
        } while (gameOption == GameMenu::null);
    } else if (menuOption == MainMenu::TUTOR) {
        system("clear");
        do
        {
            std::cout << "Please select a tutorial to use:" << std::endl;
            std::cout << "1. Arrays" << std::endl;
            std::cout << "2. Exit to Main Menu" << std::endl;
            tutormenu_select();
            system("clear");
        } while (tutorOption == TutorMenu::null);        
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
        do
        {
        std::cout << "Learn about arrays some more?" << std::endl;
        std::cout << "1. Arrays Tutorial" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        tutormenu_select();
        if (tutorOption == TutorMenu::ARRAY) {
            tutorOption = TutorMenu::null;
            goto myarrayt;
        } else if (tutorOption == TutorMenu::EXIT) {
            tutorOption = TutorMenu::null;
            goto mainmenu;
        } else
            continue;
        } while (tutorOption == TutorMenu::null);
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
}