/*
 * Title: hw1_1.cpp
 * Abstract: This program reads input numbers from a user and displays the closest                     distance between two numbers among all input numbers.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/08/2020
 */

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
  int num;
  cin >> num;
  int * arr = new int [num];
  for(int i=0; i<num; i++)
  {
    cin >> arr[i];
  }
  int min_dist = INT_MAX;
  int dis1 = 0;
  int dis2 = 0;
  for(int i=0; i<num; i++)
  {
    for(int j=i+1; j<num; j++)
    {
      if( min_dist > abs(arr[i]-arr[j]) )
      {
        min_dist = abs(arr[i]-arr[j]);
        if(arr[i]<arr[j])
        {
          dis1 = i; dis2 =j;
        }
        else
        { 
          dis1 = j; dis2 = i;
        }
      }
    }
  }
  cout << "Min distance: " << min_dist << endl;
  cout << "Two numbers for min distance: " << arr[dis1] << " and " << arr[dis2] << endl;

  return 0;
}