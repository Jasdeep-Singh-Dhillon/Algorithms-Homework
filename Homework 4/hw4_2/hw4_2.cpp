/*
 * Title: hw4_2.cpp
 * Abstract: This program determines the maximum number of apples you can collect from the boxes.
 * ID: 2867
 * Date: 09/24/2020
 */

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> powerSet(int box[], int size);
bool constraint(vector<int> vals);
void display(vector<int> vals);
int totalApples(vector<int> index, int box[], int size);

int main()
{
  int size;
  cin >> size;

  int * box = new int [size];
  for(int i=0; i<size; i++)
  {
    cin >> box[i];
  }

  vector<int> result = powerSet(box, size);
  cout << "Boxes:";
  for(int i=0; i<result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
  cout << "Max Apples:" << totalApples(result, box, size) << endl;
}

vector<int> powerSet(int box[], int size)
{
  vector<int> result;
  int apples = -1;
  for(int i=0; i<pow(2, size); i++)
  {
    vector<int> temp;
    for(int j=0; j<size; j++)
    {
      if(i & (1<<j))
      {
        temp.push_back(j);
      }
    }
    if( constraint(temp) )
    {
      int sum = totalApples(temp, box, size);
      if(sum>apples)
      {
        apples = sum;
        result = temp;
      }
    }
  }
  return result;
}

bool constraint(vector<int> vals)
{
  for(int i=0; i<vals.size(); i++)
  {
    if(vals[i+1]-vals[i]==1)
    return false;
  }
  return true;
}

void display(vector<int> vals)
{
  for(int i=0; i<vals.size(); i++)
  {
    cout << vals[i] << " ";
  }
}

int totalApples(vector<int> index, int box[], int size)
{
  int sum = 0;
  for(int i=0; i<index.size(); i++)
  {
    sum += box[index[i]];
  }
  return sum;
}