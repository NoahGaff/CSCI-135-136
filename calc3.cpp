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
    int num, sum = 0, squaredSum = 0;
    char oparator;
    
    cin >> num;
   
    while (cin >> oparator)
    {
        if (oparator == '^')
        {
            sum = squaredSum;
            if (squaredSum == 0)
                sum = pow(num,2);
        }
        else if (oparator == '-')
        {
            cin >> num;
            sum -= num;
            
            squaredSum -= pow(num,2);
        }
        else if (oparator == '+')
        {
            cin >> num;
            sum += num;
            
            squaredSum += pow(num,2);
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
