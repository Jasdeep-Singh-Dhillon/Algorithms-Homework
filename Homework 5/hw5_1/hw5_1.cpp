/*
 * Title: hw5_1.cpp
 * Abstract: This program reads a number of input values and puts 
 			 all negative numbers in front of all positive numbers
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 01/10/2020
 */

#include<iostream>
using namespace std;

void swap (int &a, int &b);
void approach1(int inp[], int size);
void approach2(int inp[], int size);

int main()
{
  int size;
  cin >> size;

  int * inp1 = new int [size];
  int * inp2 = new int [size];
  for(int i=0; i<size; i++)
  {
    cin >> inp1[i];
    inp2[i] =inp1[i];
  }

  approach1(inp1, size);
  approach2(inp2, size);

}

void swap (int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void approach1(int inp[], int size)
{
  int i=0, j=size-1;
  while(i<j)
  {
    if(inp[i]>=0 && inp[j]<0)
    {
      swap(inp[i], inp[j]);
      i++;
      j--;
      continue;
    }
    if(inp[i]<0)
    {
      i++;
    }
    if(inp[j]>0)
    {
      j--;
    }
  }

  for(int i=0; i<size; i++)
  {
    cout << inp[i] << " ";
  }
  cout << endl;
}

void approach2(int inp[], int size)
{
  int i=0, j=0;
  
  while(j<size && i<size)
  {
    if(inp[j]<0 && i>j)
    {
      j++;
    }
    if(inp[j]>=0)
    {
      j++;
    }
    else if(inp[i]<0)
    {
      i++;
    }
    else if(inp[i]>=0 && inp[j]<0)
    {
      swap(inp[i], inp[j]);
      i++;
      j++;
    }
  } 

  for(int i=0; i<size; i++)
  {
    cout << inp[i] << " ";
  }
  cout << endl;
}