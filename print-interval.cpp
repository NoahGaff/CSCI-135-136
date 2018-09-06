//
//  valid.cpp
//  136
//
//  Created by Noah Gaffney on 9/6/18.
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//

#include <iostream>
using namespace std;

int main ()
{
    int num1, num2;
    cout << "give me 2 numbers and ill give you a list of the numbers inbetween" << endl;
    cin >> num1;
    cin >> num2;
    
    for (int i = num1; i < num2; i ++)
    {
        cout << i << " ";
    }
    
    cout << endl;
    
    return 0;
}
