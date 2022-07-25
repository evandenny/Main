#ifndef _menu_h
#define _menu_h

#pragma once

#define underline "\033[4m"
#define reset "\033[0m"

enum class MainMenu {
    null,
    PLAY_GAMES,
    TUTOR,
    EXIT
};

enum class GameMenu {
    null,
    GUESS,
    EXIT
};

enum class endOfGameMenu {
    null,
    PLAY_AGAIN,
    EXIT_TO_MAIN,
    EXIT
};

enum class TutorMenu {
    null,
    ARRAY,
    EXIT
};


enum class endOfTutorMenu {
    null,
    TUTOR_AGAIN,
    EXIT_TO_MAIN,
    EXIT
};

class Menu {
public:
    static void run(void program()) {
        program();
    }
    static void displayMainMenu() {
        std::cout << "Welcome to " << underline "Evan" reset << " " << underline "Denny" reset << "'s App!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Games" << std::endl;
        std::cout << "2. Tutorials" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "-> ";
    }
    void displayGameMenu();
    void displayTutorMenu();
    void displayEndOfGameMenu();
    void displayEndOfTutorMenu();
    void switchMain();
    void switchGame();
    void switchTutor();
    void switchEndOfGame();
    void switchEndOfTutor();
    static void exiting() {
        std::cout << "Exiting..." << std::endl;
        Sleep::milliseconds(500);
        std::cout << "Goodbye!" << std::endl;
        Sleep::seconds(1);
        system("clear");
        exit(0);
    }
};

#endif