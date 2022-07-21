#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <list>
#include <math.h>
#include "framework.h"

using namespace std;

process_status framework::get_process_status() {
    return activity;
}

string framework::get_process_name() {
    return process_name;
}

list <string> framework::get_processes() {
    return processes;
}

string framework::get_active_process() {
    return active_process;
}

int framework::get_process_id(string process_name) {
    return process_id;
}

process_status framework::get_process_status_by_id(int process_id) {
    
    get_process_id();
    return activity;
}

pair <int, int> framework::get_mouse_position() {
    return mouse_position;
}

pair <int, int> framework::get_mouse_click() {
    return mouse_click;
}

void framework::set_process_name(string process) {
    process_name = process;
}

void framework::set_process_id(string process) {
    
    process_id = ;
}



void framework::loop() {
    while (get_process_status() == RUNNING) {
        input();
        logic();
        update();
        draw();
        wait();
    }
    while (get_process_status() == STOPPED) {
        input();
        wait();
    }
    while (get_process_status() == EXIT) {
        close();
    }
}

void framework::process() {
    while (get_process_status() == RUNNING) {
        loop();
        update();
        draw();
        wait();
    }
    while (get_process_status() == STOPPED) {
        loop();
        wait();
    }
    while (get_process_status() == EXIT) {
        close();
    }
}

void framework::validate() {
    if (activity == STOPPED) {
        suspend();
    }
    if (activity == EXIT) {
        close();
    } else {
        process();
    }
}

void framework::run() {
    activity = RUNNING;
    validate();
}

void framework::wait() {
    activity = STOPPED;
    validate();
}

void framework::stop() {
    activity = EXIT;
    validate();
}

void framework::input() {

}

void framework::logic() {

}

void framework::update() {

}

void framework::draw() {

}

void framework::suspend() {

}

void framework::close() {

}
void framework::handle_events() {

}

void framework::handle_input() {

}

framework::framework() {

}

framework::~framework() {
    
}