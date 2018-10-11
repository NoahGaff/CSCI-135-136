/*
 Author: Noah Gaffney
 Course: CSCI-136
 Instructor: their name
 Assignment: Lab 5 A
 Here, briefly, at least in one
 or a few sentences
 describe what the
 program does.
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
    int next = n + 1;
    while (! isPrime (next)) { next++; }
    return next;
}

int countPrimes(int a, int b)
{
    int numOfPrimes = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i)) {numOfPrimes++;}
    }
    
    return numOfPrimes;
}

bool isTwinPrime(int n)
{
    int larger = n + 2;
    int smaller = n - 2;
    
    if (isPrime(n) && (isPrime(larger) || isPrime(smaller))) { return true; }
    else {return false;}
    
}

int nextTwinPrime(int n)
{
    int next = n + 1;
    while (! isTwinPrime (next)) { next++; }
    return next;
}

int largestTwinPrime(int a, int b)
{
    int largestTwin = -1;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i)) {largestTwin = i;}
    }
    
    return largestTwin;
}

int main()
{
    int num1;
    cout << "Enter first number: ";
    cin >> num1;
    
    //int num2;
    //cout << "Enter Second number: ";
    //cin >> num2;
    
    cout << isTwinPrime(num1) << endl;
    
    return 0;
}
