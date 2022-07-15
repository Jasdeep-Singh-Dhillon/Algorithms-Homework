/*
 * Title: hw1_2.cpp
 * Abstract: This program reads two groups of numbers in which each group has random integer numbers with possible duplicates and tells if there's a duplicate number
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/02/2020
 */

#include <iostream>
using namespace std;

void sort(int a[], int size);
void swap(int &a, int &b);
int * input(int size);
void duplicate(int a[], int size1, int b[], int size2);

int main()
{
  int size1;
  cin >> size1;
  int *a = input(size1);

  int size2;
  cin >> size2;
  int *b = input(size2);  

  sort(a, size1);
  sort(b, size2);
  duplicate(a, size1, b, size2);
  
  return 0;
}

int * input(int size)
{
	int * a = new int [size];
	for(int i=0; i<size; i++)
	{
		cin >> a[i];
	}
	return a;
}

void sort(int a[], int size)
{
  for(int i=0; i<size; i++)
  {
    for(int j=i; j<size; j++)
    {
      if(a[i]>a[j])
      {
        swap(a[i], a[j]);
      }
    }
  }
}

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void duplicate(int a[], int size1, int b[], int size2)
{
	cout << "Answer:";
	bool f = false;
	for(int i=0; i<size1; i++)
	{
		if(a[i] != a[i+1])
		{
			for(int j=0; j<size2; j++)
			{
				if(a[i] == b[j] && b[j] != b[j+1] )
				{
					cout << a[i] << " ";
					f = true;
				}
			}
		}
	}
	if(f == false)
  		cout << "NONE";
  	cout << endl;
}