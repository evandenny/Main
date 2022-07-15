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
#include "framework.h"

using namespace std;

process_status framework::get_process_status() {
    return activity;
}

void framework::loop() {
    while (get_process_status == RUNNING) {
        input();
        logic();
        update();
        draw();
        wait();
    }
    while (get_process_status == STOPPED) {
        input();
        wait();
    }
    while (get_process_status == EXIT) {
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

}

void framework::wait() {

}

void framework::stop() {

}

void framework::input() {

}

void framework::logic() {

}

void framework::update() {

}

void framework::draw() {

}

void framework() {
    
}

framework::framework() {

}

framework::~framework()
{

}