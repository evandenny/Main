#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <list>
#include <cmath>
#include "account.h"

void account::set_username(std::string username) {
    this->username = username;
}

void account::set_password(std::string password) {
    this->password = password;
}

std::string account::get_username() {
    return username;
}

std::string account::get_password() {
    return password;
}

void account::create_account() {
    std::cout << "Creating account..." << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << "Account created!" << std::endl;
}

account::account(std::string username, std::string password) {
    this->username = username;
    this->password = password;
    password_ptr = &password;
}

account::~account() {
    // destructor
}