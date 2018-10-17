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
#include <cstring>
using namespace std;


int main()
{
    string prase;
    char letterAtPoint;
    getline(cin, letterAtPoint);
    
    for (int i = 0; i < prase.size(); i++)
    {
        letterAtPoint = prase[i];
        cout << letterAtPoint << " " << (int)letterAtPoint << endl; 
        
    }
    
    
    return 0;
}
