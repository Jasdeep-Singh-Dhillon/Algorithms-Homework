/*
 * Title: hw12_1.cpp
 * Abstract: This program collect maximum number of coins on an n x m board.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 12/10/2020
*/

#include<iostream>
#include<vector>
using namespace std;

vector< vector<int> > readGraph();
void printGraph(vector< vector<int> > g);
int max(int a, int b);
vector< vector<int> > coinCollect(vector< vector<int> > g);
void backtrace(vector< vector<int> > c);

int main()
{
	vector< vector<int> > g;
	g = readGraph();

	// cout << "Printing original graph: " << endl;
	// printGraph(g);
	
	vector< vector<int> > c = coinCollect(g);
	// cout << "Printing coin collect graph: " << endl;
	// printGraph(c);
	int i=c.size()-1;
	int j=c[i].size()-1;
	cout << "Max coins:" << c[i][j] << endl;

	backtrace(c);
}

vector< vector<int> > readGraph()
{
	int rows, cols;
	cin >> cols >> rows;

	vector< vector<int> > g;
	g.resize(rows);

	int temp;

	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cin >> temp;
			g[i].push_back(temp);
		}
	}
	return g;
}

void printGraph(vector< vector<int> > g)
{
	for(int i=0; i<g.size(); i++)
	{
		for(int j=0; j<g[i].size(); j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

int max(int a, int b)
{	
	if(a>b)
		return a;
	else 
		return b;
}

vector< vector<int> > coinCollect(vector< vector<int> > g)
{
	vector< vector<int> > c;
	c.resize(g.size());

	int top, left;
	for(int i=0; i<g.size(); i++)
	{
		for(int j=0; j<g[i].size(); j++)
		{	
			if(i==0 && j==0)
			{
				c[i].push_back(g[i][j]);
			}
			else if(g[i][j]==2)
			{
				c[i].push_back(-1);
			}
			else
			{
				top  = 0;
				left = 0;

				if(i!=0)
				{
					if(g[i-1][j]==2)
					{
						top = -1;
					}
					else if(g[i][j]==1)
					{
						top = c[i-1][j] + 1;
					}
					else
					{
						top = c[i-1][j];
					}
				}
				if(j!=0)
				{
					if(g[i][j-1]==2)
					{
						left = -1;
					}
					else if(g[i][j]==1)
					{
						left = c[i][j-1] + 1;
					}
					else
					{
						left = c[i][j-1];
					}
				}
				c[i].push_back(max(top, left));
			}
		}
	}
	return c;
}

void backtrace(vector< vector<int> > c)
{
	vector<int> trace;

	int i=c.size()-1;
	int j=c[i].size()-1;

	trace.push_back(j);
	trace.push_back(i);

	while(i!=0 || j!=0)
	{	
		if(i==0)
		{
			trace.insert(trace.begin(), i);
			trace.insert(trace.begin(), j-1);
			j--;
			continue;
		}
		else if (j==0)
		{
			trace.insert(trace.begin(), i-1);
			trace.insert(trace.begin(), j);
			i--;
			continue;
		}
		if(c[i-1][j] <= c[i][j-1])
		{
			trace.insert(trace.begin(), i);
			trace.insert(trace.begin(), j-1);
			j--;
		}
		else
		{
			trace.insert(trace.begin(), i-1);
			trace.insert(trace.begin(), j);
			i--;
		}
	}
	
	cout << "Path:";
	for(int i=0; i<trace.size(); i+=2)
	{
		if(i!=0)
		{
			cout << "->";
		}
		cout << "(" << trace[i] + 1
			 << "," << trace[i+1] + 1
			 << ")" ;
	}
	cout << endl;
}