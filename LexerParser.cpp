//
// Created by user on 16/12/18.
//

#include <vector>
#include <queue>
#include "Expression.h"
#include "ExpressionCommand.h"

#include "LexerParser.h"
#include <bits/stdc++.h>
#include "Command.h"
#include "CommandAssign.h"
#include "CommandVar.h"
#include "ExpressionFactory.h"
#define VAR "v"




vector<string> LexerParser::splitter(string str) {

    // Vector of string to save tokens
    vector<string> tokens;
    int i = 0, sign=0;
    string word = "";
    while(i<(str.length()-1)) {
        if ((str[i] == '=') || (str[i] == '{') || (str[i] == '}')) {
            if (str[i - 1] != ' ') {
                str.insert(i, " ");
                i++;
            }
            if (str[i + 1] != ' ') {
                str.insert(i + 1, " ");
                i++;
            }
        }
        i++;
    }

    //top case
    if(str[str.length()-1]=='}') {
        if (str[str.length()-2] != ' ') {
            str.insert(str.length()-1, " ");
        }
        str+=" ";
    }
    i=0;
    while (i < str.length()) {
        if (!(str[i] == ' ') && !(str[i] == '\n') && !(str[i] == '\r')&& !(str[i] == '\0')) {
            word += str[i];
            i++;
        } else {
            i++;
            while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\r') || (str[i] == '\0')) {
                i++;
            }
            tokens.push_back(word);
            word = "";
        }
    }
    if(word!="") {
        tokens.push_back(word);
    }
    if(tokens.back()!= "\n") {
        tokens.push_back("\n");
    }
    this->lexeredWord = tokens;
    return tokens;
}


void LexerParser::parser(vector<string> stringVector) {

    vector<string>::iterator it = this->lexeredWord.begin();
   /* map<string, Command *> commandMap = {
            {"=",   new CommandAssign(&varMap, &it)},
            {"var", new CommandVar(&varMap, &it)}
    };*/



   pthread_mutex_t mutex;
   pthread_mutex_init(&mutex, nullptr);

   pthread_cond_t cond;
   pthread_cond_init(&cond, nullptr);
   ExpressionFactory expressionFactory(&this->varMap, &it, &this->bindMap,&cond,&mutex);

    /*map<string,Expression*> mapp;
    mapp.insert({VAR,expressionFactory.create("+")});*/ //!!!

    //go over the list and for each command - execute it.
    int j=0, i=0;
    while (it != this->lexeredWord.end() && (*it) != "\n") {

        j++;
        //if the command map has no such command
        /*  if (expressionFactory.create(*it) == NULL) {
              if (this->varMap.count(*it)) { //&& (lexeredWord[index+1]=="=")) {todo
                //  commandMap.at("=")->excecute();
              } else {
                  __throw_logic_error(""); //todo write a message
              }
          } else {
              expressionFactory.create(*it)->evaluate();
          }*/
        expressionFactory.create(*it)->evaluate();

    }

}
