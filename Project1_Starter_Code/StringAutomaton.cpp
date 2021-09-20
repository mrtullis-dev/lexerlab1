//
// Created by Mason Tullis on 9/20/21.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (index == input.size()) {
        type = TokenType::UNDEFINED;
    } else if (input[index] != '\'') {
        inputRead++;
        index++;
        S1(input);
    } else if (input[index] == '\'') {
        inputRead++;
        index++;
    }
}
