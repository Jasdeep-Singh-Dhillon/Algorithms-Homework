/*
 * Title: hw4_1.cpp
 * Abstract: This program reads a number of elements in a set and then the elements of the set
      and displays all possible binary numbers and corresponding subsets one by one.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/24/2020
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void powerSet(string str[], int size);
string binaryConvert(int num, int size);

int main()
{
  int size;
  string str[10];

  cin >> size;
  for(int i=0; i<size; i++)
  {
    cin >> str[i];
  }

  powerSet(str, size);

  
}

void powerSet(string str[], int size)
{
  for(int i = 0; i < pow(2, size); i++) 
  { 
    cout << binaryConvert(i, size) << ":";
    if(i==0)
    cout << "EMPTY";
    for(int j = 0; j < size; j++) 
    { 
      if(i & (1 << (size-j-1))) 
      {
        cout << str[j] << " ";
      }
    } 
    cout << endl; 
  } 
}

string binaryConvert(int num, int size)
{
  string str="";
  if(size==0)
  return "0";
  for(int i=0; i<size; i++)
  {
    if(num==0)
    {
      str = '0' + str;
    }
    else
    {
      str = to_string(num%2) + str;
    }
    num/= 2;
  }
  return str;
}