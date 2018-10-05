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
    
    for (int i = sideLength; i > 0; i--)
    {
        int spaces = sideLength - i;
        int stars = sideLength - spaces;
        
        while (spaces > 0)
        {
            cout << " ";
            spaces --;
        }
        while (stars > 0)
        {
            cout << "*";
            stars --;
        }
        cout << endl << endl;
    }
    
    return 0;
}
