//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney on
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//  it's over 9000
// I need more comments?
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void splitOnSpace(string s, string & before, string & after) {
    // reset strings
    before = "";
    after = "";
    // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i])) { before += s[i]; i++; }
    // skip the space
    i++;
    // accumulate after space
    while (i < s.size()) { after += s[i]; i++; }
}

int main()
{
    ifstream input;
    input.open("cmudict.0.7a.txt");
    if(input.fail()){
        cout << "File did not open";
    }
    string inputWord, compareWord, w;
    
    cout << "Not found" << endl;
    cin >> inputWord;
    
    while(input >> compareWord)
    {
        if(compareWord == inputWord){
            getline(input, inputWord);
            break;
        }
    }
    string afterSpace;
    string beforeSpace;
    splitOnSpace(compareWord + inputWord, beforeSpace, afterSpace);
    splitOnSpace(compareWord + inputWord, beforeSpace, afterSpace);
    cout << "Pronounciation: " << afterSpace << endl;
    
    
    return 0;
    
}
