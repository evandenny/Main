#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

enum process_status {
    RUNNING,
    STOPPED,
    EXIT
};

enum connect_status {
    CONNECTION_ESTABLISHED,
    CONNECTION_CLOSED,
    CONNECTION_FAILED,
    CONNECTION_TIMEOUT,
    CONNECTING,
    LISTENING
};

enum window_state {
    active,
    background,
    inactive,
    closed
};

class framework {
public:
    framework() {
        string process = "";
        window_id = 0;
        window_state state = inactive;
        active_window = 0;
        window_count = 0;
        window_width = 400;
        window_height = 400;
        process_status activity = inactive;
    }
    ~framework();
    void run();
    void stop();
    void process();
    void update();
    void draw();
    void handle_events();
    void handle_input();
    // getters
    string process 
    // setters
private:
    int x, y;
    string process;
    int active_window;
    int window_count;
    int window_width;
    int window_height;
    int window_id;
    process_status activity;
    window_state state;
    framework * 
};

#endif