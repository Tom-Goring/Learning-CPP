//
// Created by Tom Goring on 06/12/2018.
//

#include <iostream>
#include <time.h>

enum class Colour { red, blue, green }; // can remove class for a simple int enum (described as "plain")
enum class Traffic_light { green, yellow, red };

Traffic_light operator++(Traffic_light& t, int) {
    // means that when an instance of traffic light is incremented it actually uses the below code
    // so when TL = green -> TL++ -> TL = yellow

    switch (t) {

        case Traffic_light::green: return t = Traffic_light::red;
        case Traffic_light::yellow: return t = Traffic_light::green;
        case Traffic_light::red: return t = Traffic_light::yellow;
    }
}

enum Days {Saturday, Sunday, Tuesday, Wednesday, Thursday, Friday}; // typical enum


void weekend_detector(int argc, char **argv) {

    time_t rawtime;
    struct tm * ptm;

    time(&rawtime);
    ptm = gmtime(&rawtime); // gets current date information and puts it in a tm struct.

    int current_day = ptm->tm_wday;

    if (current_day == Days::Thursday) {

        std::cout<<"It's thursday! Almost the weekend...";
    }
    else if (current_day == Days::Friday) {

        std::cout<<"It's Friday. Very close now.\n";
    }
    else if (current_day == Days::Saturday) {

        std::cout<<"It's the weekend!\n";
    }
    else if (current_day == Days::Sunday) {

        std::cout<<"It's the weekend!\n";
    }
}