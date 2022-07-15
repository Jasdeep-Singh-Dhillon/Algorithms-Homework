/*
 * Title: hw2_2.cpp
 * Abstract: This program reads two timestamps of two events from a user 
 			and displays the difference between the two timestamps. 
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/02/2020
 */

#include <iostream>
using namespace std;

int * input(int size);
int * difference(int start[], int end [], int size);
void print_diff(int a[], int size);

int main()
{
  int size = 3;
  int *start = input(size); // start of the event
  int *end   = input(size); //   end of the event
  int *diff  = difference (start, end, size);
  print_diff(diff, size);
  return 0;
}

int * input(int size)
{
  char temp;
  int * a = new int [size];
  for(int i=0; i<size; i++)
  {
    cin >> a[i];
    if(i != size-1)
    cin >> temp;
  }
  return a;
}

int * difference(int start[], int end [], int size)
{
  int * diff = new int [size];
  for(int i=size-1; i>=0; i--)
  {
    if( end[i]-start[i]<0 && i!=0 )
    {
      end[i-1]--;
      end[i] += 60;
    }
    else if(end[i]-start[i]<0)
    {
      end[i] += 24;
    }
    diff[i] = end[i] - start[i];
  }
  return diff;
}

void print_diff(int a[], int size)
{
  for(int i=0; i<size; i++)
  {
    if(a[i]<10)
    cout << "0";
    cout << a[i];
    if(i!=size-1)
    cout << ":";
  }
  cout << endl;
}