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
 string p="5+6*3";


 ShuntingYard shan(&map,p);

int x=shan.evaluate();
cout<<p<<"="<<shan.evaluate()<<endl;

LexerParser lexerParser;
//string string1="if 3!=5 { if 3 != 5 { var t=7 } var c=2*(3 +5) } c=6";
string string1="var x=5\n print x*-6";
vector<string>vec =lexerParser.splitter(string1);
lexerParser.parser(vec);
//cout<<endl<<lexerParser.getVarMap().at("x");
int y=6;
string yu="7";

return 0;
}


