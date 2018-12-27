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
#include "pml.h"
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


//BIndingTable *BIndingTable::map_instance = NULL;

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
  //  cout << lexerParser.getVarMap()->at("x");

    //ShuntingYard shan(&map, nullptr);

//int x=shan.evaluate();
//cout<<pp<<"="<<shan.evaluate();

//string string1="if 3!=5 { if 3 != 5 \n{ var t=7 } var c=2*(3 +5) } t=6"; //todo works
//string string1="var x=5\n print x*-6-6\n"; //todo works
    //string string1="if 3!=5 \n{ var c=2*(\n3 +5) print c}";
//string string1="var x= 5+3 + (4 * 3 )+( 2+5)\nx=3"; //todo works
//string string1= "var x=5 +1 while x!=8 {x = x +1 print x  }"; //todo works
//string string1= "var x=5  while x!=8 { x=x+1 while  x!=8 { x=x+1 }  } x=5"; //todo works
//string string1="var t= bind /instrumentation/airspeed-indicator/indicated-speed-kt var x=5 var y = bind x var z=bind x z=9"; //todo works

//string string1="var x=5";

//string string1="var x= bind \"/engines/engine/rpm\" x=5"; //todo works

  //  string string1 = "connect 172.18.32.5 5402 var x= bind \"/controls/flight/aileron\" x=-1"; //todo wotks

 // string string1 = "openDataServer 5400 10 connect 172.18.32.5 5402 var x = bind \"/controls/flight/aileron\" x=1 sleep 250"; //todo the main t -works


  /*  LexerParser lexerParser;
 string string1="var x=3+5";
    vector<string> vec = lexerParser.splitter(string1);
    lexerParser.parser(vec);

    cout << lexerParser.getVarMap()->at("x");*/
   // cout<<d->at("/controls/flight/aileron")<<endl;


//   char a;
//   cin>>a;




    pthread_exit(nullptr);

   //return 0;

}
