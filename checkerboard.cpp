/*
 Author: Noah Gaffney
 Course: CSCI-135
 Instructor: their name
 Assignment: Project 2: Part I
 
 Gives the prununciation of
 input words
 */


#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int  width;
    cout << "input width: " << endl;
    cin >> width;
    
    //Making variable height and getting input from user
    int height = 0;
    cout << "input height: " << endl;
    cin >> height;
    int checkardBoard = 0;
    
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (checkardBoard % 2 == 0)
                cout << "*";
            else
                cout << " ";
            checkardBoard++;
        }
        cout << endl;
    }
}
