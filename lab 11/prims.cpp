#include <bits/stdc++.h>
using namespace std;
//number of vertices
#define V 6


int minimumKey(int key[], bool minSpantree[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (minSpantree[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void printMST(int parent[], int graph[V][V])
{
	cout << "Edge   \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << "\t:  "
			<< graph[i][parent[i]] << " \n";
}

void prims(int graph[V][V])
{

	int parent[V];
	int key[V];
	bool minSpantree[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, minSpantree[i] = false;

	key[0] = 0;
	parent[0] = -1;


	for (int count = 0; count < V - 1; count++) {
		
		int u = minimumKey(key, minSpantree);
		minSpantree[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && minSpantree[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	
	printMST(parent, graph);
}


int main()
{
	int graph[V][V] = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
	prims(graph);
}

