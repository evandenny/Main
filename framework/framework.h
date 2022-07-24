#ifndef _FRAMEWORK_H
#define _FRAMEWORK_H

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>
#include <thread>

class Framework {
private:
    int argc;  // number of arguments
    char** argv;  // array of arguments
    std::string currentPath; // cwd
    std::string appName; // name of the application
    std::string appVersion; // version of the applicationtring
    std::string appAuthor; // author of the application
    std::string appDescription; // description of the application

    std::vector<std::string> args;
    std::vector<std::string> options;
    std::vector<std::string> flags;
    std::vector<int> intOptions;
    std::string help;
    
    std::string * args_;
    std::string * options_;
    std::string * flags_;
    int * intOptions_;
    
    std::queue<std::string> queue;
    std::queue<int> queueInt;
    std::queue<std::string> queuedAction;
    std::queue<int> queuedActionInt;

    std::pair<int, int> xy;
    std::array<std::pair<int, int>, 10> xyArray;

public:
    Framework(std::string appName, std::string appVersion, std::string appAuthor, std::string * args, std::string * options, std::string * flags, int * intOptions) {
        this->appName = appName;
        this->appVersion = appVersion;
        this->appAuthor = appAuthor;
        std::string help;
        std::string currentPath;
        int argc;
        char** argv = new char*[10];
        this->args_ = args;
        this->options_ = options;
        this->flags_ = flags;
        this->intOptions_ = intOptions;
        this->appDescription = "";
        queue = {};
        queueInt = {};
        queuedAction = {};
        queuedActionInt = {};
        xy = {};
        xyArray = {};
        args = {};
        options = {};
        flags = {};
        intOptions = {};
        int x = 20, y = 20;
        this->xy = std::make_pair(20, 20);
        this->xyArray = std::array<std::pair<int, int>, 10>();
        this->xyArray[0] = std::make_pair(20, 20);
        this->xyArray[1] = std::make_pair(0, 0);
        this->xyArray[2] = std::make_pair(0, 0);
        this->xyArray[3] = std::make_pair(0, 0);
        this->xyArray[4] = std::make_pair(0, 0);
        this->xyArray[5] = std::make_pair(0, 0);
        this->xyArray[6] = std::make_pair(0, 0);
        this->xyArray[7] = std::make_pair(0, 0);
        this->xyArray[8] = std::make_pair(0, 0);
        this->xyArray[9] = std::make_pair(0, 0);
    }
    void init(int argc, char** argv);

    void buildxyArray(int x, int y);
};


#endif