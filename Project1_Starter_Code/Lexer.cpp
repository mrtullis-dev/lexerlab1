#include "Lexer.h"
#include "Automaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include <iostream>

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;
    int maxRead = 0;
    int inputRead;
    Automaton *maxAutomaton = nullptr;
    Token *newToken = nullptr;


    while (input.size() > 0) {
        maxRead = 0;
        maxAutomaton = automata[0]; //good
    }

//    set lineNumber to 1
//    // While there are more characters to tokenize
//    loop while input.size() > 0 {
//        set maxRead to 0
//        set maxAutomaton to the first automaton in automata

    // TODO: you need to handle whitespace inbetween tokens
    while (isspace(input.at(0))) {
        if (input.at(0) == '/n') {}
        else {
            lineNumber++;
        }
        input.erase(0, 1);
        if (!input.size()) {
            newToken = new Token(TokenType::END, "", lineNumber);
            tokens.push_back(newToken);
            return;
        }



//        // Here is the "Parallel" part of the algorithm
//        //   Each automaton runs with the same input
//        foreach automaton in automata {
//            inputRead = automaton.Start(input)
//            if (inputRead > maxRead) {
//                set maxRead to inputRead
//                set maxAutomaton to automaton
//            }
//        }

        for (Automaton *automaton: automata) {
            inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
//        // Here is the "Max" part of the algorithm
//        if maxRead > 0 {
//            set newToken to maxAutomaton.CreateToken(...)
//
//                add newToken to collection of all tokens
//        }
        if (maxRead > 0) {
            Token *newToken = maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        } else {
            maxRead = 1;
            newToken = new Token(TokenType::UNDEFINED, "", lineNumber);
            tokens.push_back(newToken);
        }
        input.erase(0, maxRead);
        tokens.push_back(new Token(TokenType::END, "", lineNumber));
    }
}

        void Lexer::Print() {
            for (unsigned int i = 0; i < tokens.size(); i++) {
                std::cout << tokens.at(i)->ToString() << std::endl;
            }
            std::cout << std::endl << "Total tokens " << tokens.size() << std::endl;
        }
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
