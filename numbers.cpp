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

bool isDivisibleBy(int n, int d)
{
   if (d == 0 || n % d != 0) {return false;}
   else {return true;}
}


bool isPrime(int n)
{
   if (n <= 1) { return false; }
   
   for (int i = 2; i <= n-1; i++) 
   { 
      if (isDivisibleBy(n, i)) {return false;}
   }
   
   return true;
}

int nextPrime(int n) 
{
   while ((isPrime(n))!)
   {
      n++; 
   }
   
   return n;
}

int main() 
{
  int num1; 
  cout << "Enter first number: ";
  cin >> num1; 
  
  cout << nextPrime(num1) << endl; 
  
  return 0; 
}
