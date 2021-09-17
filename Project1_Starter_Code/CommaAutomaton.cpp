//
// Created by Mason Tullis on 9/17/21.
//

#include "CommaAutomaton.h"

void CommaAutomaton::S0(const std::string& input) {
    if (input[index] == ',') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
