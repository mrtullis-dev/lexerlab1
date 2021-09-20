//
// Created by Mason Tullis on 9/19/21.
//

#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    if(index == input.size()) {
        Serr();
    }
    else if(isspace(input[index])) {
    }
    else if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}