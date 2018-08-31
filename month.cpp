/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: I don't rememeber right now
Assignment: smaller
tells you if its a leap year
*/

// i need 
//2 more comments? 

#include <iostream>
using namespace std;

int main ()
{
    cout << "What is the year?" << endl;
    int year = 0;
    cin >> year;
    
    cout << endl;
    
    cout << "What is the month?" << endl;
    int month = 0;
    cin >> month;
    
    cout << endl;
    
    int daysInMonth = 0; 
    
    if ((month < 7) && (month % 2 == 0) || (month > 7) && (month % 2 != 0) && (month != 2)) 
      daysInMonth = 30; 
      
    else if (month == 2)
    {
      if (year % 4 != 0) {daysInMonth = 28;}
      else if (year % 100 != 0) {daysInMonth = 29;}
      else if (year % 400 != 0) {daysInMonth = 28;}
      else {daysInMonth = 29;}
    }
    
    else 
      daysInMonth = 31;
      
    cout << daysInMonth;
    
    return 0;
}
