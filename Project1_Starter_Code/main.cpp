#include <fstream>
#include "Lexer.h"

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();


    std::ifstream file;

    file.open("test.txt", std::ifstream::in);
    lexer();
    file.close();

    delete lexer;

    return 0;
}