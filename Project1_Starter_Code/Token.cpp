#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->type = type;
    this->description = description;
    this->line = line;
}

std::string Token::ToString(){
    return "(" + TokenToString(type) + ",\"" + description + "\""+ std::to_string(line) + ")";
};

std::string Token::TokenToString(TokenType token) {

    switch(type){
        case COMMA:
            return "COMMA";
            break;
        case PERIOD:
            return "PERIOD";
            break;
        case Q_MARK:
            return "Q_MARK";
            break;
        case LEFT_PAREN:
            return "LEFT_PAREN";
            break;
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
            break;
        case MULTIPLY:
            return "MULTIPLY";
            break;
        case ADD:
            return "ADD";
            break;
        case COLON:
            return "COLON";
            break;
        case COLON_DASH:
            return "COLON_DASH";
            break;
        case RULES:
            return "RULES";
            break;
        case QUERIES:
            return "QUERIES";
            break;
        case FACTS:
            return "FACTS";
            break;
        case SCHEMES:
            return "SCHEMES";
            break;
        case ID:
            return "ID";
            break;
        case STRING:
            return "STRING";
            break;
        case COMMENT:
            return "COMMENT";
            break;
        case UNDEFINED:
            return "UNDEFINED";
            break;
        case END:
            return "EOF";
            break;
        default:
            return "Default";
            break;
    }
}
