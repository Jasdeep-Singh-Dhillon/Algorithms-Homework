/*
 * Title: hw7_1.cpp
 * Abstract: This program displays the biggest number in an array with n integer 
             numbers using a divide-and-conquer technique
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 10/20/2020
*/
 
#include <iostream>
using namespace std;

void input(int *num, int size);
void print(int *num, int size);
int max(int *num, int begin, int end);

int main()
{
	int size;
  cin >> size;
	int * num = new int [size];
	input(num, size);
  cout << max(num, 0, size-1) << endl;
}

void input(int *num, int size)
{
	for(int i=0; i<size; i++)
	{
		cin >> num[i];
	}
}

void print(int *num, int size)
{
	cout << "Printing: " << endl;
	for(int i=0; i<size; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
}

int max(int *num, int begin, int end)
{
  if(begin == end)
  return num[begin];
  else
  {
    int a = max(num, begin, (begin+end-1)/2);
    int b = max(num, (begin+end+1)/2, end);
    if(a>b)
    {
      return a;
    }
    else
    {
      return b;
    }
  }
}