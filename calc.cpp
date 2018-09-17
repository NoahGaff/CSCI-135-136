//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney on
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//  it's over 9000
//

#include <iostream>
using namespace std;

int main ()
{
    int num;
    string oparator;
    int sum = 0;
    
    while (cin >> num)
    {
        cin >> oparator;
        if (oparator == "+")
        {
            sum += num;
        }
        else
        {
            sum -= num;
        }
    }
    
    cout << sum;
    
    
    return 0;
}
