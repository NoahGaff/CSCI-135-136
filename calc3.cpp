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
#include <cmath>
using namespace std;


int main ()
{
    int num, sum;
    char op;
    
    cin >> num;
    
    while (cin >> op)
    {
        if (op == '+')
        {
            sum += num;
            cin >> num;
        }
        else if (op == '-')
        {
            sum += num;
            cin >> num;
            num = -num;
        }
        else if (op == '^')
        {
            sum += num;
            num = pow(num,2);
        }
        else if (op == ';')
        {
            sum += num;
            cout << sum << endl;
            sum = 0;
        }
    }
        
    
    
    return 0;
}

