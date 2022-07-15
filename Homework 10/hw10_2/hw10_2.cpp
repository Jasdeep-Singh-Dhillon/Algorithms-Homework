/*
 * Title: hw10_2.cpp
 * Abstract: This program conducts radix sort for strings. 
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 11/20/2020
*/

#include<iostream>
#include<vector>
using namespace std;

struct Bucket
{
	vector<string> s;
};

void input_vect(vector<string> &v);
void print_vect(vector<string> v);
int max_string_len(vector<string> v);
void radix_sort(vector<string> &v);
void clear_bucket(Bucket b[], int size);
vector<string> read_bucket(Bucket b[], int size);

int main()
{
	vector<string> vect;
	input_vect(vect);
	radix_sort(vect);
}

void input_vect(vector<string> &v)
{
	int size; 
	cin >> size;

	string temp;
	for(int i=0; i<size; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
}

void print_vect(vector<string> v)
{
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int max_string_len(vector<string> v)
{
	int max_len = v[0].length();

	for(int i=0; i<v.size(); i++)
	{
		if( max_len < v[i].length() )
		{
			max_len = v[i].length();
		}
	}
	return max_len;
}

void clear_bucket(Bucket b[], int size)
{
	for(int i=0; i<size; i++)
	{
		b[i].s.clear();
	}
}

vector<string> read_bucket(Bucket b[], int size)
{
	vector<string> v;
	for(int i=0; i<size; i++)
	{
		if(b[i].s.size()>0)
		{
			for(int j=0; j<b[i].s.size(); j++)
			{
				v.push_back(b[i].s[j]);
			}
		}
	}
	return v;
}

void radix_sort(vector<string> &v)
{	
	Bucket b[27];

	int size = max_string_len(v);
	for(int i=0; i<size; i++)
	{
		for(int k=0; k<v.size(); k++)
		{
			if(v[k].size() >= (size-i) )
			{
				int index = v[k][size-i-1] - 'A' + 1;
				b[index].s.push_back(v[k]);
			}
			else
			{
				b[0].s.push_back(v[k]);
			}
		}
		cout << endl;
		v = read_bucket(b, 27);
		print_vect(v);
		clear_bucket(b, 27);
	}

}