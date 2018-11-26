/*
Author: Noah Gaffney
Course: CSCI-136
Instructor: their name
Assignment: recursion

Here, briefly, at least in one or a few sentences
describe what the program does.
*/

//i need more comments
//but i know what my code does
//but i must do as my lord grade scope comands


#include <iostream>
#include<cmath>
using namespace std;

void printRange(int left, int right)
{
  if (left <= right) {
        cout << left << " ";

        printRange(left+1, right);
    }
    else {
        cout << " ";
    }
}


int sumRange(int left, int right)
{
  int sum;

  if (right < left) { return 0; }

  else
  {
    sum = left + sumRange(left + 1, right);
  }

  return sum;
}

int sumArrayInRange(int *arr, int left, int right)
{
  int sum;

  if (right < left) { return 0; }
  else
  {
    sum = arr[left] + sumArrayInRange(arr, left + 1, right);
  }

  return sum;

}


int sumArray(int *arr, int size)
{
  return sumArrayInRange(arr, 0, size-1);
}


bool isAlphanumeric(string s)
{
  if (s.length() == 0){return true;}
  else if (!isalpha(s[0]) & !isdigit(s[0])) {return false;}
  else { return isAlphanumeric(s.substr(1, s.length() - 1)); }
}


bool nestedParens(string s)
{
  if (s.length() == 0) {return true;}
  if ((s.length() % 2) != 0) {return false;}
  if (!(s[0] == '(' && s[s.length() - 1] == ')')) {return false;}
  else {return nestedParens(s.substr(1, s.length() - 2));}
}

/*
bool divisibleHelper(int *prices, int left, int right, int acountOne, int acountTwo, int place)
{
  if ((acountOne == 0) && (acountTwo == 0)) { return true; }
  else if (acountOne - prices[left] > 0){ return divisibleHelper(prices, left + 1, right, acountOne - prices[left], acountTwo, place); }
  else { return divisibleHelper(prices, left, right, acountOne + prices[place + 1], acountTwo - prices[place + 1], place); }
  return false;

  //else if ((acountOne < 0) || (acountTwo < 0)) {return false;}
  //else if (acountOne >= acountTwo) {return divisibleHelper(prices, left + 1, right, acountOne - prices[left], acountTwo);}
  //else {return divisibleHelper(prices, left + 1, right, acountOne, acountTwo - prices[left]);}
}

*/
/*
bool divisibleHelper(int *prices, int left, int right, int acountOne, int acountTwo)
{
  if ((acountOne == 0) && (acountTwo == 0)) {return true;}
  else if ((acountOne >= acountTwo) && (acountOne - prices[left] > 0))
  {
    if ((acountOne < 0) || (acountTwo < 0)) {return false;}
    else {return divisibleHelper(prices, left + 1, right, acountOne - prices[left], acountTwo);}
  }
  else {return divisibleHelper(prices, left + 1, right, acountOne, acountTwo - prices[left]);}
}

bool divisible(int *prices, int size)
{
  int allowence;
  int sum = sumArray(prices, size);
  if (!(sum % 2 == 0)) { cout << sum; return false; }
  else { allowence = sum / 2; }

  return divisibleHelper(prices, 0, size - 1, allowence, allowence);

}
*/
/*

bool divisibleHelper(int *prices, int left, int right, int allowence, int place, int loopNumber)
{
  if (loopNumber == pow(right +1, 2)) {return false;}
  else if (sumArrayInRange(prices, 0, place) == sumArrayInRange(prices, place, right)) {return true;}
  else
  {
    if (place == right)
    {
      return divisibleHelper(prices, left, right, allowence, 0, loopNumber);
    }
    return (prices, left, right, allowence, place + 1, loopNumber + 1);
  }
}

bool divisible(int *prices, int size)
{
  int allowence;
  int sum = sumArray(prices, size);
  if (!(sum % 2 == 0)) { cout << sum; return false; }
  else { allowence = sum / 2; }

  return divisibleHelper(prices, 0, size - 1, allowence, 1, 0);
}
*/

bool checkSubset (int arr[], int n, int sum)
{
  // Base Cases
  if (sum == 0) { return true; }
  if (n == 0 && sum != 0) {return false;}

  // If last element is greater than sum, then
  // ignore it
  if (arr[n-1] > sum) {return checkSubset (arr, n-1, sum);}

  /* else, check if sum can be obtained by any of
  the following
  (a) including the last element
  (b) excluding the last element
  */
  return checkSubset (arr, n-1, sum) ||
  checkSubset (arr, n-1, sum-arr[n-1]);
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool divisible (int arr[], int n)
{
  // Calculate sum of the elements in array,
  // i.e., getting the value which is expected to be achieved, as explained 86 is the number
  int sum = sumArray(arr, n);
  
  // If sum is odd, there cannot be two subsets
  // with equal sum
  if (sum%2 != 0) {return false;}

  // Find if there is subset with sum equal to half of total sum
  return checkSubset (arr, n, sum/2);
}



int main ()
{
  int num[] = {5,4,6,3};

  cout << divisible(num, 4);
  return 0;
}

//this last one was fun
//it would be cool to have more real world onces like this
