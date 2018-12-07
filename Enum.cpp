//
// Created by Tom Goring on 06/12/2018.
//

#include <iostream>
#include <time.h>

enum class Colour { red, blue, green }; // can remove class for a simple int enum (described as "plain")
enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t, int) {
    // means that when an instance of traffic light is incremented it actually uses the below code
    // so when TL = green -> TL++ -> TL = yellow

    switch (t) {

        case Traffic_light::green: return t = Traffic_light::red;
        case Traffic_light::yellow: return t = Traffic_light::green;
        case Traffic_light::red: return t = Traffic_light::yellow;
    }
}

enum Days {Saturday, Sunday, Tuesday, Wednesday, Thursday, Friday}; // typical enum


int main(int argc, char **argv) {

    time_t rawtime;
    struct tm * ptm;

    time(&rawtime);
    ptm = gmtime(&rawtime); // gets current date information and puts it in a tm struct.

    if (ptm->tm_wday == Days::Thursday) {

        std::cout<<"It's thursday! Almost the weekend...";
    }

    Traffic_light c = Traffic_light::red;

    c = c++;

    if (c == Traffic_light::red) {

        std::cout<<"Traffic light is red.\n";
    }
    else if (c == Traffic_light::yellow) {

        std::cout<<"Traffic light is yellow.\n";
    }
    else {

        std::cout<<"Traffic light is green.\n";
    }
}