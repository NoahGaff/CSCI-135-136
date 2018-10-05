/*
 Author: Noah Gaffney
 Course: CSCI-135
 Instructor: their name
 Assignment: Project 2: Part I
 
 Gives the prununciation of
 input words
 okay
 */


#include <iostream>
#include <fstream>
using namespace std;

void splitOnSpace(string s, string & before, string & after)
{
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

string findWord(string inputWord)
{
    ifstream input;
    string compareWord, addWord;
    
    int spaces = 0;
    
    for (int i = 0; i < inputWord.size(); ++i)
        if (inputWord[i] == ' ') ++spaces;
    
    input.open("cmudict.0.7a");
    if(input.fail()){
        cout << "File did not open";
    }
    
    for(int i = 0; i < inputWord.size(); i++) { inputWord.at(i) = toupper(inputWord.at(i)); }
    
    while(input >> compareWord)
    {
        for (int i = 0; i < spaces; i++)
        {
            input >> addWord;
            compareWord = compareWord + addWord;
        }
        if(compareWord == inputWord)
        {
            getline(input, inputWord);
            break;
        }
    }
    
    return inputWord;
}




int main()
{
    string inputWord, compareWord, afterSpace, beforeSpace;
    
    cin >> inputWord;

    compareWord = findWord(inputWord);
    
    splitOnSpace(compareWord, beforeSpace, afterSpace);
    
    if (afterSpace == "") { cout << "Not found"; }
    else { cout << "Pronounciation: " << afterSpace << endl; }
    
    compareWord = findWord(afterSpace);
    
    splitOnSpace(compareWord, beforeSpace, afterSpace);
    
    cout << "Identical: " << beforeSpace << endl;
    

    
}
