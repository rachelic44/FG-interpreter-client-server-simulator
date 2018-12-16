//
// Created by user on 16/12/18.
//

#include <vector>
#include "LexerParser.h"
#include <bits/stdc++.h>

string sub(string str, int start, int end) {
    string strToBe = "";
    int i = 0;
    for (i = start; i < end; i++) {
        strToBe += str[i];
    }
    return strToBe;
}

vector<string> LexerParser::splitter(string str, char delimiter) {



    // Vector of string to save tokens
    vector <string> tokens;

    // stringstream class check1
    stringstream check1(str);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, delimiter))
    {
        if(intermediate=="") {
            continue;
        }
        tokens.push_back(intermediate);
    }
    return tokens;

}

