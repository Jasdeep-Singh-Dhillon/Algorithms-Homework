/*
 * Title: hw7_2.cpp
 * Abstract: This program reads a positive integer number from a user and reverses it.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 10/20/2020
*/

#include<iostream>
#include<cmath>
using namespace std;

int digiSize(int num);
void digits(int * vals, int num); 
int reverse(int* vals, int size);

int main()
{
  int num;
  cin >> num;
  int size = digiSize(num);
  int * vals = new int [size];
  digits(vals, num );
  cout << reverse(vals, size) << endl;
}

int digiSize(int num)
{
  int size = 0;
  while(num>0)
  {
    size++;
    num = num/10;
  }
  return size;
}

void digits(int * vals, int num)
{
  int i = 0;
  while(num>0)
  {
    vals[i] = num%10;
    num /= 10;
    i++;
  }
}

int reverse(int* vals, int size)
{
  int result = 0;
  for(int i=0; i<size; i++)
  {
    result = result*10+ vals[i];
  }
  return result;
}