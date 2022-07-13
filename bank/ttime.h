#ifndef _ttime_h_
#define _ttime_h_

#include <iostream>
#include <thread>
#include <string>
#include <chrono>

class ttime {
public:
    ttime(){};
    ////////////////////////////////
    // microsecond sleep function //
    ////////////////////////////////
    void ms250() {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    void ms500() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    void ms1000() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    void ms2000() {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    void msX(int millisec) {
        std::this_thread::sleep_for(std::chrono::milliseconds(millisec));
    }

    ////////////////////////////
    // seconds sleep function //
    ////////////////////////////
    void s1() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    void s2() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    void s3() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    void sX(int x) {
        std::this_thread::sleep_for(std::chrono::seconds(x));
    }

    ////////////////////////////////
    // microsecond sleep function //
    ////////////////////////////////
    void us250() {
        std::this_thread::sleep_for(std::chrono::microseconds(250));
    }
    void us500() {
        std::this_thread::sleep_for(std::chrono::microseconds(500));
    }
    void us1000() {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }
    void us2000() {
        std::this_thread::sleep_for(std::chrono::microseconds(2000));
    }
    void usX(int microsec) {
        std::this_thread::sleep_for(std::chrono::microseconds(microsec));
    }
};

// TO USE
// #include "ttime.h"
// ttime t;
// t.ms250();
// t.ms500();
// t.sX(10)

#endif // !_ttime_h_