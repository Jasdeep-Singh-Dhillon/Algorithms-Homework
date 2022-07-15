/* Title: hw5_2.cpp
 * Abstract: This program that reads an input graph data from a user and
             presents a path for the travelling salesman problem (TSP)
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 01/10/2020
*/

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void empty(int **graph, int size);
void input(int **graph, int size, int edges);
void print(int **graph, int size);
void print_vector(vector<int> vect);
vector<int> display(vector<int> vertices);
vector<vector<int>> find_permutations(vector<int> vertices);
vector<int> total_cost(vector<vector<int>> permutation, int **graph, int start);
int min_cost_index(vector<int> cost);
bool isPossible(int **graph, int size, int start);
 

int main()
{
  //getting the size of the 2d-array
  int size;
  cin >> size;

  //declaring the 2d-array based on size
  int **graph = new int*[size];
  for(int i=0; i<size; i++)
  {
    graph[i] = new int [size];
  }

  //making all the points to 0 
  // while the making the diagonal -1
  empty(graph, size);

  //taking the number of inputs for the graph
  int edges;
  cin >> edges;
  
  //takes the edge weight with vertice values
  input(graph, size, edges);
  
  //takes the start point of the path
  int start; 
  cin >> start;

  //if possible to get the path without revisiting vertices
  if(!isPossible(graph, size, start))
  {
    cout << "Path:" << endl;
    cout << "Cost: -1" << endl;
    return 0;
  }
  
  //making a vector to store all the vertices other than the start
  vector<int> vertices;
  for(int i=0; i<size; i++)
  {
    if(i != start)
    vertices.push_back(i);
  }

  //storing all possible permutations of vertices
  vector<vector<int>> permutation = find_permutations(vertices);
  
  //calculating the total cost for each permutation
  vector<int> cost = total_cost(permutation, graph, start);

  //getting index for the best path
  int index = min_cost_index(cost);

  //printing the best path
  cout << "Path:" << start << "->";
  for(int i=0; i<permutation[index].size(); i++)
  {
    cout << permutation[index][i];
    cout << "->";
  }
  cout << start << endl;
  
  //calculating the min of the total cost
  cout << "Cost:" << cost[index] << endl;
  return 0;
}

void empty(int **graph, int size)
{
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      graph[i][j] = 0;
    }
  }
}

void input(int **graph, int size, int edges)
{
  for(int i=0; i<edges; i++)
  {
    int vert1, vert2, weight;
    cin >> vert1 >> vert2 >> weight;
    if(vert1>size || vert2>size)
    break;
    graph[vert1][vert2] = weight;
  }
}

void print(int **graph, int size)
{
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      cout << graph[i][j] << " ";
      if(graph[i][j]<10)
      cout << " ";
    }
    cout << endl;
  }
}
 
vector<int> display(vector<int> vertices) 
{ 
  vector<int> vertex;
  for (int i = 0; i < vertices.size(); i++) 
  { 
    vertex.push_back(vertices[i]); 
  } 
  return vertex; 
} 

// A function to identify all permutations 
vector<vector<int>> find_permutations(vector<int> vertices) 
{ 
  vector<vector<int>> permutation;
  // Sort the given array first.
  sort(vertices.begin(), vertices.end()); 
  // Find all possible permutations 
  int i=0;
  do 
  { 
    permutation.push_back(display(vertices));
    i++;
  } while (next_permutation(vertices.begin(), vertices.end())); 
  return permutation;
}

vector<int> total_cost(vector<vector<int>> permutation, int **graph, int start)
{
  vector<int> total;

  for(int i=0; i<permutation.size(); i++)
  {
    int sum = 0;
    sum = sum + graph[start][permutation[i][0]];
    for(int j=0; j<permutation[i].size()-1; j++)
    {
      if(graph[permutation[i][j]][permutation[i][j+1]]==0)
      {
        sum = -1;
        break;
      }
      sum = sum+graph[permutation[i][j]][permutation[i][j+1]];
    }
    if(graph[permutation[i][permutation[i].size()-1]][start]!=0 && sum != -1)
    sum = sum+ graph[permutation[i][permutation[i].size()-1]][start];
    else 
    sum = -1;

    total.push_back(sum);
  }
  return total;
}

int min_cost_index(vector<int> cost)
{
  int min = INT_MAX;
  int index = -1;

  for(int i=0; i<cost.size(); i++)
  {
    if(min > cost[i] && cost[i]!=-1)
    {
      min = cost[i];
      index = i;
    }
  }
  return index;
}

bool isPossible(int **graph, int size, int start)
{
  for(int i=0; i<size; i++)
  {
    if(graph[i][start]!=0)
    return true;
  }
  return false;
}

void print_vector(vector<int> vect)
{
  for(int i=0; i<vect.size(); i++)
  {
    cout << vect[i] << " ";
  }
}