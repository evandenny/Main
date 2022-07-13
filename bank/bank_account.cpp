#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "ttime.h"
using namespace std;

ttime t;

/////////////////////////
// account enumeration //
/////////////////////////

enum account_type {
    physical,
    digital,
    both
};
enum account_status {
    active,
    inactive
};

enum Bank_Account_Type {
    checking,
    savings,
    cd,
    brokerage,
    credit_card,
    line_of_credit,
    mortgage
};

//////////////////////////
// terminal enumeration //
//////////////////////////

// use in terminal class in different cpp file
enum terminal_cmds {
    withdraw,
    balance,
    transfers,
    account,
    help,
    quit
};

////////////////////////
// bank account class //
////////////////////////

class Bank_Account {
public:
    Bank_Account(string name, string user, string pass, Bank_Account_Type account_type){
        this->name = name;
        username = user; 
        password = pass; 
        ptr_password = &password; // pointer to password for encryption purposes
        this->account_type = account_type; // enum account_type checking, savings, cd, brokerage, credit_card, line_of_credit, mortgage  
        enum account_status status = active; // enum account_status active, inactive
        const string BANK = "Wells_Fargo"; // bank name
        const string CURRENCY = "USD"; // currency type
    };
    string getUsername() {
        return username;
    };
    string getName() {
        return name;
    };
    string newName(string n) {
        name = n;
        return n;
    };                     
    string newPassword(string newPassword) {
        *ptr_password = newPassword;
        return *ptr_password;
    };
    string newUsername(string newUsername) {
        username = newUsername;
        return username;    
    };
    void printAccount() {
        cout << "New Bank Account created for: " << getName() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Password: " << ptr_password << endl;
    };
    string inputUsername() {
        string user;
        cout << "Enter your username: ";
        cin >> user;
        return user;
    }
    void inputPassword() {
        string user = inputUsername();
        string input;
        cout << "Enter your password: ";
        cin >> input;
        if (user == this->username && input == *this->ptr_password) {
            login();
        } else {
            for (int i = 0; i < 3; i++) {
                cout << "Incorrect password. " << "(" << 3 - i << ") attempts remaining.\n";
                string user = inputUsername();
                cout << "Enter your password: ";
                cin >> input;
                if (user == this->username && input == *this->ptr_password) {
                    break;
                } else if (i == 2) {
                    cout << "You have been locked out of your account.\n";
                    exit(0);
                } else {
                    continue;
                } // end if
            } // end for loop
            login(); 
        }   // end else
    }  // end inputPassword
    void login() {
        string terminal;
        cout << "Welcome to your account " << this->name << "!\n";
        t.ms1000();
        cout << "What would you like to do?\n"; 
        t.msX(450);
        cout << "Type 'help' for a list of commands.\n";
        t.usX(500);
        continue;
    }; // end login
    void createAccount() {
        string name;
        string user;
        string pass;
        string account_type;
        cout << "Enter your name: ";
        cin >> name;
        t.ms250();
        cout << "Enter your username: ";
        cin >> user;
        t.ms250();
        cout << "Enter your password: ";
        cin >> pass;
        t.ms500();
        cout << "Enter an account type (checking, savings, or brokerage): ";
        cin >> account_type;
        Bank_Account newAccount(name, user, pass, account_type);
        t.s1();
        newAccount.printAccount();
    }; // end createAccount
private:
    string name;
    string username;
    string * ptr_password;
    string password;
    enum Bank_Account_Type account_type;
// Constants for bank
    const string BANK = "Wells Fargo";
    const string CURRENCY = "USD";
    enum account_status status = active;
};

int main() {
    Bank_Account DennyEvan("Evan Denny", "evandenny", "pisswort", checking);
    DennyEvan.printAccount();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    DennyEvan.inputPassword();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0; // end main
}