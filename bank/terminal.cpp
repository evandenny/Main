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

// terminal enumeration //
//////////////////////////

enum terminal_bankcmds {
    withdraw,
    balance,
    transfers,
    account,
    help,
    quit
};

enum terminal_basiccmds {
    list,
    run,
    view,
    close,
    about,
    help,
    exit
};

// menu enumeration //
//////////////////////

enum menu {
    main_menu,
    account_menu,
    transfer_menu,
    brokerage_menu,
    credit_card_menu,
    help_menu
};

enum account_page {
    checking_account,
    savings_account,
    cd_account,
    brokerage_account,
    brokerage_cash,
    credit_card_account,
    exit
}

////////////////////////
// terminal class //////
////////////////////////
// bank account class //
class Deposit_Withdraw : public WF_Account_Program {
public:
    void run();
    void deposit(double amount);
    void withdraw(double amount);
    void balance();
    void account_selection();
    void account_selection_menu();
    void account_selection_menu_options();
    void exit();
private:
    int balance;
    int withdraw;
    int deposit;
    int transfer;
    int account;
    int help;
    int quit;
};

////////////////////////
// terminal class //////
////////////////////////
// bank account class //
class Accounts : public WF_Account_Program {
public:
    void run();
    void checking_account();
    void savings_account();
    void cd_account();
    void brokerage_account();
    void credit_card_account();
    void exit();
private:
    account_page account;
    double checking_balance;
    double savings_balance;
    double cd_balance;
    double brokerage_balance;
    double credit_card_balance;
    double brokerage_cash;
    double credit_card_balance;
    double credit_card_interest;
    double credit_card_interest_rate;
    double credit_card_monthly_payment;
};

enum transfer {
    checking_to_savings,
    savings_to_checking,
    savings_to_cd,
    cd_to_savings,
    savings_to_brokerage,
    brokerage_to_savings,
};

////////////////////////
// terminal class //////
////////////////////////
// bank account class //
class Transfers : public WF_Account_Program {
public:
    void run();
    void checking_to_savings();
    void savings_to_checking();
    void savings_to_cd();
    void cd_to_savings();
    void exit();
private:
    transfer type;
};

////////////////////////
// terminal class //////
////////////////////////
// bank account class //
class Main_Menu : public WF_Account_Program {
public:
    void run();
    void main_menu();
    void main_menu_options();
    void exit();
private:
    main_menu menu;

};

////////////////////////
// terminal class //////
////////////////////////
class WF_Account_Program : public terminal {
public:
    WF_Account_Program() {
        // constructor
    }
    ~WF_Account_Program() {
        // destructor
    }
    void run() {
        // main loop
    }
    void print_menu() {
        // print menu
    }
    void print_help() {
        // print help
    }
    void print_account_info() {
        // print account info
    }
    void print_account_balance() {
        // print account balance
    }
    void print_account_transfers() {
        // print account transfers
    }
    void print_account_status() {
        // print account status
    }
    void print_account_type() {
        // print account type
    }
    void print_account_name() {
        // print account name
    }
    void print_account_username() {
        // print account username
    }
    void print_account_password() {
        // print account password
    }
private:
    string name;
    string username;
    string password;
    string *ptr_password;
    enum Bank_Account_Type account_type;
    enum account_status status;
    const string BANK = "Wells_Fargo";
    const string CURRENCY = "USD";

    terminal_bankcmds bank_cmd;
};


// terminal class //
class terminal {
public:
    terminal(  void run();
    void command (string cmd);
    
    void display_menu();
    void help();

    void login();
    void logout();
protected:

private:
    terminal_basiccmds cmds;
    terminal_bankcmds bcmds;
};