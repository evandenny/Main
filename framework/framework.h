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
#include <list>

using namespace std;

enum process_status {
    RUNNING,
    STOPPED,
    EXIT
};

enum window_state {
    active,
    background,
    inactive,
    closed
};

class framework {
public:
    framework();
    ~framework();
    void run();
    void stop();
    void process();
    void loop();
    void validate();
    void wait();
    void input();
    void logic();
    void update();
    void draw();
    void suspend();
    void handle_events();
    void handle_input();
    void close();
    // getters
    process_status get_process_status();
    string get_process_name();
    list <string> get_processes();
    string get_active_process();
    int get_process_id(string process_name);
    process_status get_process_status_by_id(int process_id);

    pair <int, int> get_mouse_position();
    pair <int, int> get_mouse_click();
    // setters
    void set_process_name(string process);
    void set_process_id(string process);
    void set_process_list(vector<string> processes);
    void set_active_process(string process_id);
    void set_process_status(int process_id, process_status status);
private:
    // process info
    list <string> processes;
    string active_process;
    string process_name;
    int process_id;
    process_status activity;

    pair <int, int> mouse_position;
    pair <int, int> mouse_click;
};

#endif