#ifndef ACCOUNT_H // include guard
#define ACCOUNT_H // Prevent multiple inclusion

#pragma once // Include this file only once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

class account  
{
public:
    account();
    ~account();


private:
    std::string name;
    std::string password;
    const std::string * password_ptr;

#endif // ACCOUNT_H // include guard