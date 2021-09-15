#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum class TokenType {
    COLON,
    COLON_DASH,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    END //this means EOF if it does not print.
};

class Token
{
private:
    // TODO: add member variables for information needed by Token

public:
    Token(TokenType type, std::string description, int line);
    // need to implement ToString();

    // TODO: add other needed methods
};


#endif // TOKEN_H

