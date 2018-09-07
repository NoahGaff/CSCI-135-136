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
    int index, value;
    int myData [10] = {1,1,1,1,1,1,1,1,1,1};
    
    do {
        
        for (int i = 0; i < 10; i++)
            cout << myData[i] << " ";
        
        cout << endl << endl << "Input index: ";
        cin >> index;
        
        cout << "Input value: ";
        cin >> value;
        cout << endl;
        
        if (index <= 10 && index >= 0)
        {
            myData[index] = value;
        }
        
    } while (index <= 10 && index >= 0);
    
    
    return 0;
}
