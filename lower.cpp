/*
 Author: Noah Gaffney
 Course: CSCI-135
 Instructor: their name
 Assignment: Project 2: Part I
 
 Gives the prununciation of
 input words
 */


#include <iostream>
using namespace std;
int main()
{
    int sideLength;
    
    cout << "Input side length: ";
    cin >> sideLength;
    
    for (int i = 0; i <= sideLength; i++)
    {
        for (int g = 0; g < i; g++)
        {
            cout << "*";
        }
        cout << endl << endl;
    }
    
    return 0;
}
