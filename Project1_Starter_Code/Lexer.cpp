#include "Lexer.h"
#include "Automaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "LeftParenAutomaton.h"
#include "RightParenAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include <iostream>

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new StringAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new CommentAutomaton());

    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    int maxRead = 0;
    int inputRead = 0;
    Automaton *maxAutomaton = nullptr;
    Token *newToken = nullptr;


    while (input.size() > 0) {
        maxRead = 0;
        maxAutomaton = automata.at(0); //good


        if(isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                lineNumber++;
                //input.erase(0,1);
            }
            input.erase(0, 1);
            continue;
        }



        for (Automaton *automaton: automata) {
            inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        if (maxRead > 0 && ((input.at(0) != '\'' && input.at(maxRead - 1) != '\'') || (input.at(0) == '\'' && input.at(maxRead - 1) == '\''))) {
            string thisInput = input.substr(0,maxRead);
            Token *newToken = maxAutomaton->CreateToken(thisInput, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        } else {
            if (maxRead == 0) maxRead = 1;
            newToken = new Token(TokenType::UNDEFINED, input.substr(0,maxRead), lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(input.begin(), input.begin()+maxRead);
        //tokens.push_back(new Token(TokenType::END, "", lineNumber));
    }
    tokens.push_back(new Token(TokenType::END, "", lineNumber));


    //input = input.substr(maxRead, input.size()); //i dont need this?

    //for (Token *token: tokens) { std::cout << tokens << std::endl; }
    Print();
}

void Lexer::Print() {
    for (unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << tokens.at(i)->ToString(); if(tokens.at(i) == tokens.back()) {} else{cout << std::endl;};
    }
    std::cout << std::endl << "Total Tokens = " << tokens.size() << std::endl;
}

//    set lineNumber to 1
//    // While there are more characters to tokenize
//    loop while input.size() > 0 {
//        set maxRead to 0
//        set maxAutomaton to the first automaton in automata

    // TODO: you need to handle whitespace inbetween tokens



//        // Here is the "Parallel" part of the algorithm
//        //   Each automaton runs with the same input
//        foreach automaton in automata {
//            inputRead = automaton.Start(input)
//            if (inputRead > maxRead) {
//                set maxRead to inputRead
//                set maxAutomaton to automaton
//            }
//        }


//        // Here is the "Max" part of the algorithm
//        if maxRead > 0 {
//            set newToken to maxAutomaton.CreateToken(...)
//
//                add newToken to collection of all tokens
//        }

//        // No automaton accepted input
//        // Create single character undefined token
//        else {
//            set maxRead to 1
//                set newToken to a  new undefined Token
//                (with first character of input)
//                add newToken to collection of all tokens
//        }
//        // Update `input` by removing characters read to create Token
//        remove maxRead characters from input
//    }
//    add end of file token to all tokens
