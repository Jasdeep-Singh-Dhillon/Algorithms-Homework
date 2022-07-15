/*
 * Title: hw6_1.cpp
 * Abstract: This program conducts the BFS traversal of a graph and displays 
 			 city names in the range of hop(s) from a starting city
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 09/10/2020
*/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

void read_graph(vector< vector<string> > & g);
void print_graph(vector< vector<string> > g);
int get_index(vector< vector<string> > g, string s);
void bfs(vector<vector<string>> & g, string src);


int main()
{
  vector< vector<string> > graph;
  read_graph(graph);
  
  sort(graph.begin(), graph.end());

  string source;
  cin >> source;

  bfs(graph, source);

  return 0;
}

void read_graph(vector< vector<string> > & g)
{
  int size;
  cin >> size;
  g.resize(size);

  string temp;
  for(int i=0; i<size; i++)
  {
    cin >> temp;
    g[i].push_back(temp);
  }

  int edges;
  cin >> edges;
  string a, b;
  for(int i=0; i<edges; i++)
  {
    cin >> a >> b;
    g[get_index(g, a)].push_back(b);
  }
}

void print_graph(vector< vector<string> > g)
{
  cout << "\nPrinting graph: \n";
  for(int i=0; i<g.size(); i++)
  {
    for(int j=0; j<g[i].size(); j++)
    {
      if(j!=0)
      {
        cout << "->";
      }
      cout << g[i][j] ;
    }
    cout << endl;
  }
}

int get_index(vector< vector<string> > g, string s)
{
  for(int i=0; i<g.size(); i++)
  {
    if(g[i][0]==s)
    return i;
  }
  return -1;
}

void bfs(vector<vector<string>> & g, string src)
{
  int hops;
  cin >> hops;
  queue<string> q;
  vector<int> mark(g.size(), -1);
  mark[get_index(g, src)] = 0;
  q.push(src);

  while(!q.empty())
  {
    string current = q.front(); 
    q.pop();
    int index = get_index(g, current);
    for(int i=0; i<g[index].size(); i++)
    {
      string neighbor = g[index][i];
      int n_index = get_index(g, neighbor);
      if(mark[n_index] == -1)
      {
        mark[n_index] = mark[index]+1;
        q.push(neighbor);
      }
    }
    
  }
  for (int i = 0; i < g.size(); i++)
	{
    	if(mark[i]<=hops && mark[i]>=0)
		cout << g[i][0] << ": " << mark[i] << endl;
	}
}