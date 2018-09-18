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
    char oparator;
    
    int sum = 0;
    
    while (!cin.fail())
    {
    
        cin >> sum;
    
        while (cin >> oparator)
        {
            cin >> num;
            if (oparator == '-')
            {
                sum -= num;
            }
            else if (oparator == '+')
            {
                sum += num;
            }
            else if (oparator == ';')
            {
                break;
            }
    
        }
        
        cout << sum;
    }
    
    return 0;
}
