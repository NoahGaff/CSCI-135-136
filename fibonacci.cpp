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
    // make an array
    int fib[60];
    // first two terms are given
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < 59; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    for (int i = 0; i < 59; i++)
        cout << fib[i] << endl;
    
    return 0;
}
