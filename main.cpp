/**
 * Flight Gear Project (:
 * By Racheli Copperman 315597575
 * By Yael Dagan 307894899
 */
#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Divide.h"
#include "Multiply.h"
#include "Number.h"
#include "LexerParser.h"
#include <stack>
#include <map>
#include "ShuntingYard.h"
#include "LexerParser.h"
#include "DictionaryPath.h"
#include "BoundMap.h"
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include "BoolSingelton.h"
#include <fstream>

DictionaryPath *DictionaryPath::map_instance = NULL;
BoolSingelton* BoolSingelton::boolInstance=NULL;
BoundMap *BoundMap::map_instance = NULL;

using namespace std;

string turnFileToString (string fileName ) {
    ifstream myfile (fileName);
    string line;
    string whole="";
    if(!myfile.is_open()) {
        myfile.open(fileName,fstream::app | fstream::in);
    }
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
           whole+=line+" ";
        }
        myfile.close();
    } else {
        throw "Could not open file";
    }
    return whole;
}

int main(int args,char **argv) {

    string fileScript;
if(args==1) {
    throw "No file nme or script defined\n";
} else if(args==2) {
    fileScript=turnFileToString(argv[1]);
} else {
    throw "Too Many raguments";
}
   LexerParser lexerParser;
   vector<string> vec = lexerParser.splitter(fileScript);
   lexerParser.parser(vec);
   return 0;
}
