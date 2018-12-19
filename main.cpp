#include <iostream>
#include "Expression.h"
#include "BinaryExpression.h"
#include "UnaryExpression.h"
#include "Plus.h"
#include "Minus.h"
#include "Divide.h"
#include "Multiply.h"
#include "Number.h"
#include "LexerParser.h"
#include <stack>
#include <stack>
#include <map>
#include "ShuntingYard.h"
#include "LexerParser.h"


#include <pthread.h>
#include <iostream>

using namespace std;

int main() {


 map<string, double> map;
 string p="3+2/4";
 ShuntingYard shan(&map,p);


cout<<p<<"="<<shan.evaluate();

LexerParser lexerParser;
string string1="if 3==5 {\n var c=2 \n}\n";
vector<string>vec =lexerParser.splitter(string1);
lexerParser.parser(vec);
cout<<endl<<lexerParser.getVarMap().at("c");
int y=6;
string yu="popp";

return 0;
}
