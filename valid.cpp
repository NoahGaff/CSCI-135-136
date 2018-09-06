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
    int num;
    cout << "give me a number inbetween 0 and 100:" << endl;
    cin >> num;
    
    while ((num < 0) || (num > 100))
    {
        cout << "I'm sorry, the number you entered was not in the requested peramiters";
        cout << endl << "give me a number inbetween 0 and 100:" << endl;
        cin >> num;
    }
    
    int squaredNum = num * num;
    
    cout << "the number you entered squared is: " << squaredNum << endl;
    
    return 0;
}
