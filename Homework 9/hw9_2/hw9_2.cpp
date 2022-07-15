/*
 * Title: hw9_2.cpp
 * Abstract: This program conducts the topological sorting based on the Kahn’s algorithm
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 11/12/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void read_graph(vector< vector<int> > & g);
void print_graph(vector< vector<int> > g);
vector<int> inDegree(vector< vector<int> > g);
void print_degree(vector<int> d);
vector<int> kahn_algo(vector< vector<int> > g, vector<int> d);
void print_order(vector<int> k);

int main()
{
	vector< vector<int> > graph;
	read_graph(graph);
	vector<int> degree = inDegree(graph);
	print_degree(degree);
	vector<int> order = kahn_algo(graph, degree);
	if(order.size()!=graph.size())
	{
		cout << "No Order:" << endl;
	}
	else
	{
		print_order( order );
	}
}

void read_graph(vector< vector<int> > &g)
{
	int size;
	cin >> size;
	g.resize(size);

	int edges;
	cin >> edges;
	int from, to;
	for(int i=0; i<edges; i++)
	{
		cin >> from >> to;
		g[from].push_back(to);
	}
}

void print_graph(vector< vector<int> > g)
{
	for(int i=0; i<g.size(); i++)
	{
		cout << i ;
		for(int j=0; j<g[i].size(); j++)
		{
			cout << "->" << g[i][j];
		}
		cout << endl;
	}
}

vector<int> inDegree(vector< vector<int> > g)
{
	vector<int> degree(g.size(), 0);

	for(int i=0; i<g.size(); i++)
	{
		for(int j=0; j<g[i].size(); j++)
		{
			degree[g[i][j]]++;
		}
	}
	return degree;
}

void print_degree(vector<int> d)
{
	for(int i=0; i<d.size(); i++)
	{
		cout << "In-degree[" << i 
			 << "]:" << d[i] << endl;
	}
}

vector<int> kahn_algo(vector< vector<int> > g, vector<int> d)
{
	queue<int> q;
	vector<int> k;

	for(int i=0; i<d.size(); i++)
	{
		if(d[i]==0)
		{
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int current = q.front();
		k.push_back(current);
		q.pop();
		for(int i=0; i<g[current].size(); i++)
		{
			int temp = g[current][i];
			d[temp]--;
			if(d[temp]==0)
			{
				q.push(temp);
			}
		}
	}
	return k;
}

void print_order(vector<int> k)
{
	cout << "Order:";
	for(int i=0; i<k.size(); i++)
	{
		if(i!=0)
			cout << "->";
		cout << k[i];
	}
	cout << endl;
}