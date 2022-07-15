/*
 * Title: hw11_1.cpp
 * Abstract: This program simulates the operations of linear probing.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 12/5/2020
*/

#include<iostream>
#include<vector>
using namespace std;

class Pair
{
	public:
	Pair();
	Pair(int v);
	Pair(int v, string s);
	void setValue(int v);
	void setStatus(string s);
	void setVar(int v, string s);
	int getValue();
	string getStatus();
	void display();
	private:
	int value;
	string status;
};

Pair::Pair()
{
	value = 0;
	status = "Empty"; 
}
Pair::Pair(int v)
{
	value = v;
	status = "Active";
}
Pair::Pair(int v, string s)
{
	value = v;
	status = s;
}
void Pair::setValue(int v)
{
	value = v;
}
void Pair::setStatus(string s)
{
	status = s;
}
void Pair::setVar(int v, string s)
{
	value = v;
	status = s;
}
int Pair::getValue()
{
	return value;
}
string Pair::getStatus()
{
	return status;
}
void Pair::display()
{
	cout << "Value: " << value << endl;
	cout << "Status: " << status << endl;
}

class LinProb
{
	private:
	Pair *ptr;
	int elements;
	int size;
	public:
	LinProb();
	LinProb(int s);
	void setPair(int v, string s, int index);
	void insert(int value);
	void displayStatus(int index);
	int tableSize();
	string search(int value);
	void vDelete(int value);
	void nextPrime();
	void rehash();
	void displayAll();
};

LinProb::LinProb()
{
	ptr = new Pair[2];
	size = 2;
	elements = 0;
}
LinProb::LinProb(int s)
{
	ptr = new Pair[size];
	size = s;
	elements = 0;
}
void LinProb::setPair(int v, string s, int index)
{
	ptr[index].setVar(v, s);
	++elements;
	if( (elements/(float)size) > 0.5)
	{
		rehash();
	}
}
void LinProb::insert(int value)
{
	int index = value%size;

	if(ptr[index].getStatus() != "Active")
	{
		setPair(value, "Active", index);
		return;
	}

	for(int i=(index+1)%size; i!=index; i=(i+1)%size)
	{
		if(ptr[i].getStatus() != "Active")
		{
			setPair(value, "Active", i);
			break;
		}
	}
}
void LinProb::displayStatus(int index)
{	
	if(ptr[index].getStatus()!="Empty")
	{
		cout << ptr[index].getValue() << " ";
	}
	cout << ptr[index].getStatus() << endl;	
}
int LinProb::tableSize()
{
	return size;
}
string LinProb::search(int value)
{
	int index = value%size;

	int i = index;
	do
	{
		if(ptr[i].getStatus() == "Active")
		{
			if(ptr[i].getValue() == value)
			{
				return "Found";
			}
		}
		i = (i+1)%size;
	}while(i!=index);
	return "Not found";
}
void LinProb::vDelete(int value)
{
	int index = value%size;

	int i = index;
	do
	{
		if(ptr[i].getStatus() == "Active")
		{
			if(ptr[i].getValue() == value)
			{
				ptr[i].setStatus("Deleted");
				elements--;
				break;
			}
		}
		i = (i+1)%size;
	}while(i!=index);
}
void LinProb::nextPrime()
{
	size = 2*size;
	while(true)
	{
		int count = 0;
		for(int i=1; i<=size; i++)
		{
			if(size%i == 0)
			{
				count++;
			}
		}
		if(count>2)
		{
			size++;
		}
		else
		{
			break;
		}
	}
}
void LinProb::rehash()
{
	vector<int> vect;

	for(int i=0; i<size; i++)
	{
		if(ptr[i].getStatus()=="Active")
		{
			vect.push_back(ptr[i].getValue());
		}
	}

	delete [] ptr;
	nextPrime();

	ptr = new Pair[size];
	elements = 0;

	for(int i=0; i<vect.size(); i++)
	{
		insert(vect[i]);
	}

}
void LinProb::displayAll()
{
	cout << endl << "Size: " << size << endl;
	cout << "Elements: " << elements << endl;
	for(int i=0; i<size; i++)
	{
		cout << i <<": "; displayStatus(i);
	}
	cout << endl;
}

int main()
{
	int size;
	cin >> size;

	LinProb hash(size);

	int instruct;
	cin >> instruct;

	string str;
	int temp;
	for(int i=0; i<instruct; i++)
	{
		cin >> str;
		if(str == "insert")
		{
			cin >> temp;
			hash.insert(temp);
		}
		else if(str == "displayStatus")
		{
			cin >> temp;
			hash.displayStatus(temp);
		}
		else if(str == "tableSize")
		{
			cout << hash.tableSize() << endl;
		}
		else if(str == "search")
		{
			cin >> temp;
			cout << temp  << " "
			     <<	hash.search(temp)
			     << endl;
		}
		else if(str == "delete")
		{
			cin >> temp;
			hash.vDelete(temp);
		}
		else
		{
			cout << "Enter valid input" << endl;
		}
	}
}