#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Lexer.h"

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    ifstream file ("test.txt");
    file.open("test.txt");
    if(file.is_open()){
        string fileArgument = argv[1];
        ifstream file(fileArgument);
        string fileContent((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        lexer->Run(fileContent);
    } else { cout << "not open" << endl; }


    file.close();


    delete lexer;

    return 0;
}