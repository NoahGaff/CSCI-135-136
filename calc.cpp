//
//  valid.cpp
//  136
//  9/6/18
//  Created by Noah Gaffney on
//  Copyright © 2018 Noah Gaffney. All rights reserved.
//  it's over 9000
//

/*
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
*/

#include <iostream>
using namespace std;

int main ()
{
    string input, concatonatedInput;
    int calulatedOut;
    
    while (cin >> input)
    {
        concatonatedInput = concatonatedInput + input;
    }
    
    calulatedOut = stoi(concatonatedInput);
    
    cout << calulatedOut;
    
    
    return 0;
}

