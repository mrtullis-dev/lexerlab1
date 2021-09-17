//
// Created by Mason Tullis on 9/17/21.
//

#ifndef PROJECT1_STARTER_CODE_PERIODAUTOMATON_H
#define PROJECT1_STARTER_CODE_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_PERIODAUTOMATON_H
