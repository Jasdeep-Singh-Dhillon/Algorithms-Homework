/*
 * Title: hw3_1.cpp
 * Abstract: This program reads a set of events and displays the maximum number
             of events that take place concurrently.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/16/2020
 */

#include <iostream>
using namespace std;

int minimum(int a[], int size);
int maximum(int a[], int size);

int main()
{
  int size;
  cin >> size;

  int * start = new int[size];
  int * end = new int [size];

  for(int i=0; i<size; i++)
  {
    cin >> start [i];
    cin >> end[i];
  }

  int max_events = 0;
  int min = minimum(start, size);
  int max = maximum(end,   size);
  
  for(int i=min; i<=max; i++)
  {
    int count = 0;
    for(int j=0; j<size; j++)
    {
      if( i>=start[j] && i<end[j])
        count++;
    }
    if(count > max_events)
      max_events = count;
  }

  cout << "Max events: " << max_events << endl;
  return 0;
}

int minimum(int a[], int size)
{
  int min = a[0];
  for(int i=0; i<size; i++)
  {
    if(min > a[i])
    {
      min = a[i];
    }
  }
  return min;
}
int maximum(int a[], int size)
{
  int max = a[0];
  for(int i=0; i<size; i++)
  {
    if(max < a[i])
    {
      max = a[i];
    }
  }
  return max;
}