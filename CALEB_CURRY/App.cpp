#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <random>
#include "Sleep.h"
#include "ArrayTutorial.h"

#define underline "\033[4m"
#define reset "\033[0m"

//std::mt19937 type is a random number generator//
//the seeded_eng() function is a constructor for the std::mt19937 type
//the seed_seq() function constructs a seed sequence from a seed{value} array of the rd(), a random_device type object that functions as a source of randomness producing a number of random bits
//simply, the seed{} array is a container for the seed values OF...
//the rd() function that generates a random number
std::mt19937 seeded_eng() {
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    return std::mt19937(seed);
}

//the Random class contains the mt19937 random number generator//
//the mt19937 type eng contains the same mt19937 type seeded_eng() function that seeds the random number generator
//publicly, the operator() function uses int a and int b to generate a random number between a and b BY...
//the std::uniform_int_distribution<(of the integer type)> type is a distribution that generates random numbers distributed between int a and b
//the return value of the distribution is a random number between a and b
class Random {
    std::mt19937 eng = seeded_eng();
public:
    auto operator()(int a, int b) {
        std::uniform_int_distribution<int> dist(a, b);
        return dist(eng);
    }
};

/*This code works by using the following variables and functions in the following way...
 * 1. A random number generator is created.
 * 2. A random number is generated.
 * 3. The random number is checked to see if it is in the range of the desired number.
 * 4. If the random number is in the range, the random number is returned.
 * 5. If the random number is not in the range, the function is called again.
 * 6. The function is called until the random number is in the range.
 * 7. Eventually, the random number is returned.
*/

//class for enumeration of the main menu for the app
enum class MainMenu {
    PLAY_GAMES,
    TUTOR,
    EXIT,
    null
};

enum class TutorMenu {
    ARRAY,
    EXIT,
    null
};

//class for enumeration of the games menu for the app
enum class GameMenu {
    GUESS,
    EXIT,
    null
};

//chrono functions | creating a class would be a bit of a pain
void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
void sleepms(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

//function to run a game
void run(void program()) {
    program();
}

//game menu object
GameMenu gameOption = GameMenu::null;
//main menu object
MainMenu menuOption = MainMenu::null;
//tutorial menu oject
TutorMenu tutorOption = TutorMenu::null;
//string to store user input
std::string selection;
//base high score for GUESSING GAME game 
int high_score_guessgame = 10;

//function to exit the app
void exiting() {
    std::cout << "Exiting..." << std::endl;
    sleepms(500);
    std::cout << "Goodbye!" << std::endl;
    sleep(1);
    system("clear");
    exit(0);
}

//GUESSING GAME function
void Guessing_Game() {
    Random random;
    int number = random(1, 100);
    int guess = 0;
    int tries = 0;
    while (guess != number) {
        std::cout << underline "      GUESSING GAME      " reset << std::endl;
        sleepms(100);
        std::cout << "|--High Score-> " << high_score_guessgame << " tries." << std::endl; 
        std::cout << "|-Your tries-> " << tries << std::endl << std::endl;
        std::cout << "Guess a number between 1 and 100:\n" << "-> ";
        std::cin >> guess;
        if (guess == number) {
            tries++;
            std::cout << "Wow! You guessed the number in " << tries << " tries!" << std::endl;
            if (tries < high_score_guessgame) {
                high_score_guessgame = tries;
                std::cout << "New high score! " << high_score_guessgame << " tries" << std::endl;
            }
            sleep(2);
            selection = "";
            while (selection != "1" && selection != "2") {
                system("clear");
                std::cout << underline "Play again?\n" reset << std::endl;
                std::cout << "1. Play" << std::endl;
                std::cout << "2. Go to Main Menu" << std::endl;
                std::cout << "3. Exit" << std::endl;
                std::cout << "-> ";
                getline(std::cin, selection);
                if (selection == "1") {
                    system("clear");
                    run(Guessing_Game);
                } else if (selection == "2") {
                    return;
                } else if (selection == "3") {
                    system("clear");
                    std::cout << "Thanks for playing!" << std::endl;
                    sleep(1);
                    exiting();
                } else if (selection == "" || selection == " ") {
                    sleepms(10);
                } else {
                    std::cout << "Invalid selection" << std::endl;
                }
                sleepms(400);
                continue;
            }
        } else if (guess > 100 || guess < 1) { //implement way to quit game if user enters q or quit, e or exit, etc.
            std::cout << "Invalid guess! Try again..." << std::endl;
        } else if (abs(guess-number) >= 50) {
            tries++;
            std::cout << "You're freezing cold!" << std::endl;
        } else if (abs(guess-number) >= 25) {
            tries++;
            std::cout << "You're cold!" << std::endl;
        } else if (abs(guess-number) >= 15) {
            tries++;
            std::cout << "You're warm!" << std::endl;
        } else if (abs(guess-number) >= 10) {
            tries++;
            std::cout << "You're very warm!" << std::endl;
        } else if (abs(guess-number) >= 5) {
            tries++;
            std::cout << "You're hot!" << std::endl;
        } else if (abs(guess-number) >= 1) {
            tries++;
            std::cout << "You're very hot!" << std::endl;
        } else {
            //invalid character
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        sleepms(1200); //Increased to 1200
        system("clear");
    }
}

//MAIN MENU function
void mainmenu_select() {
    std::cout << "-> ";
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
        sleep(1);
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
        sleep(1);
    }
}

void tutormenu_select() {
    std::cout << "-> ";
    getline(std::cin, selection);
    if (selection == "1") {
        tutorOption = TutorMenu::ARRAY;
    } else if (selection == "2") {
        tutorOption = TutorMenu::EXIT;
    } else {
        tutorOption = TutorMenu::null;
        std::cout << "Invalid selection." << std::endl;
        Sleep::seconds(1);
    }
}

void tutormenu_select2() {
    std::cout << "-> ";
    getline(std::cin, selection);
    if (selection == "1") {
        tutorOption = TutorMenu::ARRAY;
    } else if (selection == "2") {
        tutorOption = TutorMenu::EXIT;
    } else if (selection == "3") {
        exiting();
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
        std::cout << "Welcome to " << underline "Evan" reset << " " << underline "Denny" reset << "'s App!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Play Games" << std::endl;
        std::cout << "2. Tutorials" << std::endl;
        std::cout << "3. Exit" << std::endl;
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
        exiting();
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
        run(ArrayTutorial);
        system("clear");
        do
        {
        std::cout << "Learn about arrays some more?" << std::endl;
        std::cout << "1. Arrays Tutorial" << std::endl;
        std::cout << "2. Exit to Main Menu" << std::endl;
        std::cout << "3. Exit" << std::endl;
        tutormenu_select2();
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
        sleep(1);
        std::cout << "Ready!" << std::endl;
        sleepms(500);
        system("clear"); 
        // Game Code
        run(Guessing_Game);
        system("clear");
        goto mainmenu;
    } else if (gameOption == GameMenu::EXIT) {
        gameOption = GameMenu::null;
        goto mainmenu;
    }
    return 0;
}