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
    window_state get_window_state();
    
    string get_process_name();
    list <string> get_processes();
    string get_active_process();
    int get_process_id();
    process_status get_process_status(int process_id);

    string get_window_title();
    int get_window();
    int get_active_window();
    int get_window_count();
    int get_window_height();
    int get_window_width();
    window_state get_window_state(int window_id);
    string get_window_title_by_id(int window_id);
    pair <int, int> get_window_size_by_id(int window_id);

    pair <int, int> get_mouse_position();
    pair <int, int> get_mouse_click_position();

    framework* get_framework();
    vector<framework*> get_processes_framework();
    vector<framework*> get_windows_framework();
    vector<framework*> get_threads_framework();
    vector<framework*> get_processes_threads_framework();
    vector<framework*> get_files_framework();
    // setters
    void set_process_name(string process);
    void set_process_id(string process);
    void set_process_list(vector<string> processes);
    void set_active_process(string process_id);
    void set_process_status(int process_id, process_status status);
    void set_window_title(string title);

    void set_window_title(string title);
    void set_window(int window);
    void set_active_window(int window);
    void set_window_count(int count);
    void set_window_height(int height);
    void set_window_width(int width);
    void set_window_state(int process_id, process_status status, window_status state);
    void set_pair_window_size(int window, pair <int, int> size);

    void set_framework_pointer(framework* f);
    void set_processes_framework_pointer(vector<framework*> f);
    void set_windows_framework_pointer(vector<framework*> f);
    void set_threads_framework_pointer(vector<framework*> f);
    void set_files_framework_pointer(vector<framework*> f);
private:
    // process info
    list <string> processes;
    string active_process;
    string process_name;
    int process_id;
    process_status activity;

    string window_title;
    int window;
    int active_window;
    int window_count;
    int window_width;
    int window_height;
    window_state state;
    pair <int, int> window_size;

    pair <int, int> mouse_position;
    pair <int, int> mouse_click;
    framework * pointer;
    vector<framework *> windows;
    vector<framework *> processes;
    vector<framework *> threads;
    vector<framework *> files;
};

#endif