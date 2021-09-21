//
// Created by Mason Tullis on 9/20/21.
//

#ifndef PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
#define PROJECT1_STARTER_CODE_STRINGAUTOMATON_H


#include "Automaton.h"

class StringAutomaton : public Automaton
{
public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);
    void S1(const std::string& input);
    void S2(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
