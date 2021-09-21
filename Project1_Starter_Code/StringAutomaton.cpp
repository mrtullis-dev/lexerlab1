//
// Created by Mason Tullis on 9/20/21.
//

#include "StringAutomaton.h"
#include <ostream>
#include <iostream>

using namespace std;

void StringAutomaton::S0(const std::string &input) {
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string &input) {
    if (index > input.size()) {
        Serr();
    }
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S2(input);
    }

    if(index < input.size()){
        index++;
        inputRead++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string &input) {
    if (index > input.size()) {
        index++;
        inputRead++;
    }
    if (input[index] == '\'' && inputRead > 1) {
        index++;
        inputRead++;
        S1(input);
    }
}

void StringAutomaton::S3(const std::string &input) {

}

