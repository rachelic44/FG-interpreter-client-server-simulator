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
    map<string,int> m;
map<string,int&> m2;
m.insert({"a",5});
m2.insert({"a",m.at("a")});
m.at("a")=3;
int & p=m.at("a");
m2.insert({"y",p});
int yy;


 map<string, double> map;

 string p="-4+5";


 //ShuntingYard shan(&map, nullptr);

//int x=shan.evaluate();
//cout<<p<<"="<<shan.evaluate();

LexerParser lexerParser;
//string string1="if 3!=5 { if 3 != 5 \n{ var t=7 } var c=2*(3 +5) } c=6"; //todo works
//string string1="var x=5\n print x*-6-6\n"; //todo works
// string string1="if 3!=5 \n{ var c=2*(\n3 +5) print c}";
//string string1="var x= 5+3 + (4 * 3 )+( 2+5)\nx=3"; todo works
string string1= "var x=5 +1 while x!=8 {x = x +1 print x  }";


vector<string>vec =lexerParser.splitter(string1);
lexerParser.parser(vec);
cout<<lexerParser.getVarMap().at("x");
int y=6;
string yu="7";


return 0;
}
