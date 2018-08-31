
/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: I don't rememeber right now
Assignment: smaller

this does a thing with telling 
the user which number is smaller
*/

#include <iostream>
using namespace std;

int main ()
{
    cout << "give me a number" << endl;
    int num1 = 0;
    cin >> num1;
    
    cout << endl;
    
    cout << "give me another number" << endl;
    int num2 = 0;
    cin >> num2;
    
    cout << endl;
    
    if (num1 < num2)
        cout << num1 << "is smaller";
    else
        cout << num2  << "is smaller";
    
    return 0;
}
