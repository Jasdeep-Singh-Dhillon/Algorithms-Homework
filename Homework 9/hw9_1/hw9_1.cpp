/*
 * Title: hw9_1.cpp
 * Abstract: This program connects several connected components of a graph with 
   minimum number of edges to create a single connected component of the graph.
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
vector<int> bfs(vector<vector<int>> g);
bool connectingEdges(vector<vector<int>> & g, int index);

int main()
{
	vector< vector <int> > graph;
	read_graph(graph);
	if(!connectingEdges(graph, 0))
		cout << "No new edge:" << endl;
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

vector<int> bfs(vector<vector<int>> g)
{
	int src = 0;
  	queue<int> q;
    int count = 0;
    vector<int> mark(g.size(), 0);
    mark[src] = ++count;
    q.push(src);
    while (!q.empty())  
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < g[curr].size(); i++) 
        {
            int neighbor = g[curr][i];
            if(mark[neighbor] == 0) {
                mark[neighbor] = ++count;
                q.push(neighbor);
            }
        }
    }

    return mark;
}

bool connectingEdges(vector<vector<int>> & g, int index)
{
	vector<int> mark = bfs(g);
	for(int i=0; i<mark.size(); i++)
	{
		if(mark[i]==0)
		{
			g[index].push_back(i);
			cout << "Edge: " << index << "-" << i << endl;
			connectingEdges(g, i);
			return true;
			break;
		}
	}
	return false;
}