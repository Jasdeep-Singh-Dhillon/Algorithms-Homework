/*
 * Title: hw3_2.cpp
 * Abstract: This program converts a directed graph data from 
 			 a user into a corresponding adjacency list format.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/16/2020
 */

#include <iostream>
using namespace std;

int main()
{
  int size;
  cin >> size;

  int map[50][50];

  int edge;
  cin >> edge;

  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      map[i][j] = 0;
    }
  }

  for(int i=0; i<edge; i++)
  {
    int a, b;
    cin >> a >> b;
    map[a][b] = 1;
  }

  for(int i=0; i<size; i++)
  {
    cout << i;
    for(int j=0; j<size; j++)
    {
      if(map[i][j]==1)
      {
        cout << "->" << j;
      }
      
    }
    cout << endl;
  }
  return 0;
}