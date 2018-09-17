//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney on
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//  it's over 9000
// I need more comments?
// 

#include <iostream>
using namespace std;

int main ()
{
    int num;
    string oparator;
    
    int sum = 0;
    
    cin >> sum;
    
    while (cin >> oparator)
    {
        cin >> num;
        if (oparator == "+")
        {
            sum += num;
        }
        else if (num < 0)
        {
            sum -= abs(num);
        }
        else
        {
            sum -= num;
        }
    }
    
    cout << sum;
    
    
    return 0;
}

