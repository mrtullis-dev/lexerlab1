//
// Created by Mason Tullis on 9/17/21.
//

#include "MultiplyAutomaton.h"

void MultiplyAutomaton::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
