/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: I don't rememeber right now
Assignment: smaller
tells you if its a leap year
*/

#include <iostream>
using namespace std;

int main ()
{
    cout << "give me a year" << endl;
    int year = 0;
    cin >> year;
    
    cout << endl;
    
    /*
    if (year is not divisible by 4) then (it is a common year) 
    else if (year is not divisible by 100) then (it is a leap year) 
    else if (year is not divisible by 400) then (it is a common year) 
    else (it is a leap year)
    */
    
    if (year % 4 != 0) {cout << "Common year"}
    else if (year % 100 != 0) {cout << "Leap year"}
    else if (year % 400 != 0) {cout << "Common year"}
    else {cout << "Leap year"}
    
    return 0;
}
