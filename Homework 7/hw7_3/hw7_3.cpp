/*
 * Title: hw7_3.cpp
 * Abstract: This program conducts the BFS traversal of a graph and displays 
 			 city names in the range of hop(s) from a starting city
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/10/2020
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void read_graph(vector< vector<int> > &g);
void print_graph(vector< vector<int> > g);
void sort_graph(vector< vector<int> > &g);
void algoDfs(vector< vector<int> > g);
void dfs(vector< vector<int> > g, vector<int>& mark, int index);

int count = 0;

int main()
{
  vector<vector<int>> graph;
  read_graph(graph);
  sort_graph(graph);
  algoDfs(graph);
}

void read_graph(vector< vector<int> > &g)
{
  int size;
  cin >> size;
  g.resize(size);

  int edges;
  cin >> edges;
  int index, value;
  for(int i=0; i<edges; i++)
  {
    cin >> index >> value;
    g[index].push_back(value);
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
void sort_graph(vector< vector<int> > &g)
{
  for(int i=0; i<g.size(); i++)
  {
    sort(g[i].begin(), g[i].end());
  }
}
void algoDfs(vector< vector<int> > g)
{
  
  vector<int> mark(g.size(), 0);
  
  for(int i=0; i<g.size(); i++)
  {
    if(mark[i]==0)
    {
      dfs(g, mark, i);
    }
  }
  for(int i=0; i<mark.size(); i++)
  {
    cout << "Mark[" << i << "]:" 
         << mark[i]<< endl;
  }
}

void dfs(vector< vector<int> > g, vector<int> & mark, int index)
{
  ::count = ::count+1;
  mark[index] = ::count;
  for(int i=0; i<g[index].size(); i++)
  {
    if(mark[g[index][i]]==0)
    {
      dfs(g, mark, g[index][i]);
    }
  }
}
