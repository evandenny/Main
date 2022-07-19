#include <iostream>
#include <string>
#include <chrono>
#include <thread>

enum class MainMenu {
    PLAY_GAME,
    EXIT
};

MainMenu menuOption;

int main() {
    system("clear");
    do {
        std::cout << "Welcome to Evan's App!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Game" << std::endl;
        std::cout << "2. Exit" << std::endl;
        int selection;
        std::cin >> selection;
        switch (selection) {
            case 1:
                menuOption = MainMenu::PLAY_GAME;
                break;
            case 2:
                menuOption = MainMenu::EXIT;
                break;
            default:
                std::cout << "Invalid selection." << std::endl;
                break;
        }
        system("clear");
    } while (menuOption != MainMenu::EXIT || menuOption != MainMenu::PLAY_GAME);
    if (menuOption == MainMenu::PLAY_GAME) {
        std::cout << "Starting Game..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Game Started!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
        system("clear");
        // Temporary code to test menu
        std::this_thread::sleep_for(std::chrono::seconds(3));
        // Game Code
        //run(Guessing_Game());
    } else if (menuOption == MainMenu::EXIT) {
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Goodbye!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
    return 0;
}