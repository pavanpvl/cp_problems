/*
// A C++ Program to detect cycle in a graph 
#include<bits/stdc++.h> 

using namespace std; 

class Graph 
{ 
	int V; // No. of vertices 
	list<int> *adj; // Pointer to an array containing adjacency lists 
	bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic() 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); // to add an edge to graph 
	bool isCyclic(); // returns true if there is a cycle in this graph 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
	if(visited[v] == false) 
	{ 
		// Mark the current node as visited and part of recursion stack 
		visited[v] = true; 
		recStack[v] = true; 

		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator i; 
		for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		{ 
			if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
				return true; 
			else if (recStack[*i]) 
				return true; 
		} 

	} 
	recStack[v] = false; // remove the vertex from recursion stack 
	return false; 
} 
void printcycle(bool *rec,int n){
    for(int i=0;i<n;i++)
    {
        if(rec[i]) cout<<i<<" ";
    }
    cout<<"\n";
    return ;
}

// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	bool *visited = new bool[V]; 
	bool *recStack = new bool[V]; 
	for(int i = 0; i < V; i++) 
	{ 
		visited[i] = false; 
		recStack[i] = false; 
	} 

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for(int i = 0; i < V; i++) 
		if (isCyclicUtil(i, visited, recStack)){
            cout<<i<<"\n"; 
            printcycle(recStack,V);
			return true; 
        }

	return false; 
} 

int main() 
{ 
	// Create a graph given in the above diagram 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in","r",stdin);
    freopen("/home/pavan/cp_problems/a.out","w",stdout);
    #endif
	Graph g(6); 
	g.addEdge(4, 3); 
	g.addEdge(2, 4); 
	g.addEdge(3, 5); 
	g.addEdge(3, 2); 
	g.addEdge(1, 4);  

	if(g.isCyclic()) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 
*/
#include <iostream>

using namespace std;

int N, E;
bool V[100][100];
bool visited[100];
int path[100];
int k, l;

void reset()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			V[i][j] = false;
		}
		visited[i] = false;
		path[i] = -1;
	}
	k = -2;
	l = -2;
}

void input()
{

	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int x, y;
		cin >> x >> y;
		V[x][y] = true;
	}
}

int recur(int node, int counter)
{
	path[counter] = node;

	for (int y = 0; y < N; y++)
	{
		if (V[node][y])
		{
			if (visited[y])
			{
				k = y;
				l = node;
				return -1;
			}
			visited[y] = true;
			int i = recur(y, counter + 1);
			if (i == -1)
			{
				return -1;
			}
			visited[y] = false;
		}
	}
	return -1;
}

void driver()
{

	for (int x = 0; x < N; x++)
	{
		visited[x] = true;
		path[0] = x;

		for (int y = 0; y < N; y++)
		{
			if (V[x][y])
			{
				if (visited[y])
				{
					if (x == y)
					{
						// self loop
						k = -1;
						return;
					}
				}
				visited[y] = true;
				int ret = recur(y, 1);
				if (ret == -1)
				{
					return;
				}
				visited[y] = false;
			}
		}
	}
}

void output()
{

	cout << endl;
	if (k == -2)
	{
		cout << -1 << endl; // no cycle
		return;
	}
	if (k == -1)
	{
		cout << path[0] << endl;
	}

	int start_idx = 0;
	for (int i = 0; i < 100; i++)
	{
		if (path[i] == k)
		{
			start_idx = i;
		}
	}
	for (int i = start_idx; i < 100; i++)
	{
		if (path[i] == l)
		{
			cout << path[i] << "->";
			break;
		}
		cout << path[i] << "->";
	}
	cout << path[start_idx];
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("/home/pavan/cp_problems/a.in", "r", stdin);
	freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
	reset();
	input();
	driver();
	output();

	return 0;
}
