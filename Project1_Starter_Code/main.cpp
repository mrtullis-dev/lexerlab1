#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "Lexer.h"

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    ifstream file (argv[1]);
    file.open(argv[1]);
    if(file.is_open()){
        string fileContent((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        lexer->Run(fileContent);
   } else { cout << "not open" << endl; }


    file.close();


    delete lexer;

    return 0;
}