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
    int num, sum = 0;
    char oparator;
    
    cin >> sum;
   
    while (cin >> oparator >> num)
    {
        if (oparator == '^')
        {
            sum = sum + num^2;
        }
        else if (oparator == '-')
        {
            cin >> num;
            sum -= num;
        }
        else if (oparator == '+')
        {
            cin >> num;
            sum += num;
        }
        else if (oparator == ';')
        {
            cout << sum << endl;
            cin >> num;
            sum = num;
        }
        
        
    }
    
    return 0;
}
