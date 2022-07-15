/*
 * Title: hw10_1.cpp
 * Abstract: This program conducts heap operations.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 11/20/2020
*/

#include<iostream>
#include<vector>
using namespace std;

class Heap
{
	private:
	vector<int> array;
	int size;
	public:
	Heap();
	Heap(vector<int> v);
	void displayMax();
	void insert(int val);
	void deleteVal(int val);
	void deleteMax();
	void display();
	void update(int val, int index);
	void heapify(int index);
	bool isHeap();
	void swap(int &a, int &b);
	void buildHeap();
};

Heap::Heap()
{
	array.push_back(0);
}

Heap::Heap(vector<int> v)
{
	array.push_back(0);

	for(int i=0; i<v.size(); i++)
	{
		array.push_back(v[i]);
	}

	if(isHeap())
		cout << "This is a heap." << endl;
	else
		cout << "This is NOT a heap." << endl;
	buildHeap();
}

void Heap::buildHeap()
{
	for(int i=(array.size()/2); i>0; i--)
	{
		heapify(i);
	}
}

void Heap::displayMax()
{
	if(array.size()>=2)
		cout << array[1] << endl;
}

void Heap::insert(int val)
{
	array.push_back(val);
	buildHeap();
}

void Heap::deleteVal(int val)
{
	for(int i=0; i<array.size(); i++)
	{
		if(val == array[i])
		{
			swap(array[i], array[array.size()-1]);
			array.erase(--array.end());
			break;
		}
	}
	buildHeap();
}

void Heap::deleteMax()
{
	swap(array[1], array[array.size()-1]);
	array.erase(--array.end());
	buildHeap();
}

void Heap::display()
{
	for(int i=1; i<array.size(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void Heap::update(int val, int index)
{
	array[index] = val;
	buildHeap();
}

void Heap::heapify(int index)
{
	int max = index;
	int l = index*2;
	int r = (index*2)+1;

	if( l<array.size())
	{
		if(array[l]>array[max])
		max = l;
	}

	if( r<array.size())
	{
		if(array[r]>array[max])
		max = r;
	}

	if(max != index)
	{
		swap(array[index], array[max]);
		heapify(max);
	}
}

bool Heap::isHeap()
{

	for(int i=1; i<(array.size()+1)/2; i++)
	{
		if( array[i]<array[2*i] | array[i]<array[(2*i)+1] )
		{
			return false;
		}
	}
	return true;
}

int max(vector<int> v)
{
	int max = v[0];
	for(int i=0; i<v.size(); i++)
	{
		if(max < v[i])
		{
			max = v[i];
		}
	}
	return max;
}

void input_vect(vector<int> & v)
{
	int size; 
	cin >> size;

	int temp;
	for(int i=0; i<size; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
}

void Heap::swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{	
	vector<int> vect;
	input_vect(vect);
	
	Heap h(vect);

	int commands;
	cin >> commands;

	string inp;
	int temp1, temp2;
	for(int i=0; i<commands; i++)
	{
		cin >> inp;
		if(inp == "displayMax")
			h.displayMax();
		else if(inp == "insert" )
		{
			cin >> temp1;
			h.insert(temp1);
		}
		else if(inp == "delete")
		{
			cin >> temp1;
			h.deleteVal(temp1);
		}
		else if(inp == "display")
		{
			h.display();
		}
		else if(inp == "update")
		{
			cin >> temp1 >> temp2;
			h.update(temp2, temp1);
		}
		else if(inp == "deleteMax")
		{
			h.deleteMax();
		}
		else
		{
			cout << "Enter a valid operation";
		}
	}

}