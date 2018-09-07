//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney on
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//
//  gradescope is buggy

#include <iostream>
using namespace std;

int main ()
{
    int num1, num2;
    cout << "give me two numbers and ill give you a list of the numbers inbetween" << endl;
    cin >> num1;
    cin >> num2;
    
    for (int i = num1; i < num2; i ++)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}
