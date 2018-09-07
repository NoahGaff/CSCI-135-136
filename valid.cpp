
//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//  fun and giggles
//
//

#include <iostream>
using namespace std;

int main ()
{
    int num;
    cout << "give me a number inbetween 0 and 100:" << endl;
    cin >> num;
    
    while ((num < 1) || (num > 99))
    {
        cout << "I'm sorry, the number you entered was not in the requested peramiters";
        cout << endl << "give me a number inbetween 0 and 100:" << endl;
        cin >> num;
    }
    
    int squaredNum = num * num;
    
    cout << "the number you entered squared is: " << squaredNum << endl;
    
    return 0;
}
