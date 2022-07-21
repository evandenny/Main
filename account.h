#ifndef ACCOUNT_H // include guard
#define ACCOUNT_H // Prevent multiple inclusion

#pragma once // Include this file only once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

class account {
public:
    account();
    ~account();
    // setters
    void set_username(std::string username);
    void set_password(std::string password);
    // getters
    std::string get_username();
    std::string get_password();
    // methods
    void login();
    void logout();
    void create_account();
    void delete_account();
    void change_password();
    void change_username();
private:
    std::string username;
    std::string password;
    const std::string * password_ptr;
}

#endif // ACCOUNT_H // include guard