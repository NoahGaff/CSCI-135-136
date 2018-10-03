/*
 Author: Noah Gaffney
 Course: CSCI-135
 Instructor: their name
 Assignment: Project 2: Part I
 
 Gives the prununciation of
 input words
 */


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
    input.open("cmudict.0.7a");
    if(input.fail()){
        cout << "File did not open";
    }
    string inputWord, compareWord, w;
    
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
