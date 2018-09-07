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
        
        if (index < 10)
        {
            myData[index] = value;
        }
        
} while (index < 10);
    
    
    return 0;
}
