/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: their name
Assignment: Lab 5 A

Here, briefly, at least in one 
or a few sentences
describe what the program does.
*/

#include <iostream>
using namespace std;

bool isPrime(int n)
{
   if (n <= 1)
   {
      return false; 
   }
   else if
   {
      for (i = 2; i < n-1; i++) { return isDivisibleBy(n, i); }
   }
   else {return true;} 
}

bool isDivisibleBy(int n, int d)
{
   if (d == 0 || n % d != 0) {return false;}
   else {return true;}
}

int main() 
{
  int num1; 
  cout << "Enter first number: ";
  cin >> num1; 
  
  cout << isPrime(num1) << endl; 
  
  return 0; 
}
