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
    int height, width;
    
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    
    
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (row % 2 == 0)
            {
                if (col % 2 == 0)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else
            {
                if (col % 2 == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}
