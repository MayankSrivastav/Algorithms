// Graph algorithms

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

const int V = 8;
const int DFS_BLACK = 1;
const int DFS_WHITE = -1;

#pragma region Graph DS
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;
#pragma endregion

int dfs_num[V];
int dfs_low[V];
int dfs_parent[V];
bool articulationVertex[V];
int dfs_root = 0;
int rootChildren = 0;
int dfsNumberCounter = 0;
AdjList adjlist(8);

#define TRVii(c, it) for (vii::iterator it = c.begin(); it != c.end(); ++it)
#define Rep(i, a, b) for (int i = int(a); i <= int(b); ++i)

// DFS traversal, uses macros TRVii
void dfs(int u)
{
	cout << u;
	dfs_num[u] = DFS_BLACK;

	TRVii(adjlist[u], v)
		//for (vii::iterator it = adjlist[u].begin(); it != adjlist[u].end(); ++it)
		if (dfs_num[v->first] == DFS_WHITE)
			dfs(v->first);
}

// Articulation point and Bridge finding
void ArticulationPointAndBridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	TRVii(adjlist[u], v)
		if (dfs_num[v->first] == DFS_WHITE) {
			dfs_parent[v->first] = u;
			if (u == dfs_root) // if > 2 children, then articulation point
				rootChildren++;
			ArticulationPointAndBridge(v->first);

			if (dfs_low[v->first] >= dfs_num[u]) // for articulation point
				articulationVertex[u] = true;
			if (dfs_low[v->first] > dfs_num[u])	// for bridge
				printf(" Edge (%d %d) is a bridge\n", u, v->first);
			dfs_low[u] = min(dfs_low[u], dfs_num[v->first]); // update dfs_low		
		}
		else if (v->first != dfs_parent[u]) // back edge and not direct cycle
			dfs_low[u] = min(dfs_low[u], dfs_num[v->first]); // update dfs_low
}

int main()
{
#pragma region Graph input
	adjlist[0].push_back(make_pair(1, 0));
	//adjlist[0].push_back(make_pair(8, 0)); // new
	adjlist[1].push_back(make_pair(0, 0));
	adjlist[1].push_back(make_pair(2, 0));
	adjlist[1].push_back(make_pair(3, 0));
	//adjlist[2].push_back(make_pair(0, 0)); // new
	adjlist[2].push_back(make_pair(1, 0));
	adjlist[2].push_back(make_pair(3, 0));
	adjlist[3].push_back(make_pair(4, 0));
	adjlist[3].push_back(make_pair(1, 0));
	adjlist[3].push_back(make_pair(2, 0));
	adjlist[4].push_back(make_pair(3, 0));
	adjlist[5].push_back(make_pair(5, 0));
	adjlist[6].push_back(make_pair(7, 0));
	adjlist[7].push_back(make_pair(6, 0));
	//adjlist[8].push_back(make_pair(0, 0));
#pragma endregion

#pragma region Connected Component
	/*int numComponent = 0;
	memset(dfs_num, false, sizeof(dfs_num));
	Rep(i, 0, V - 1)
	if (dfs_num[i] == false) {
	printf("Component %d, visit:", ++numComponent);
	dfs(i);
	printf("\n");
	}*/
#pragma endregion

#pragma region DFS
	//dfs(6);
#pragma endregion 

#pragma region Articulation Point
	dfsNumberCounter = 0;
	memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	printf("Bridges: \n");
	Rep(i, 0, V - 1)
		if (dfs_num[i] == DFS_WHITE) {
			dfs_root = i;
			rootChildren = 0;
			ArticulationPointAndBridge(i);
			articulationVertex[dfs_root] = (rootChildren > 1); // special case
		}

	printf("Articulation Ponints:\n");
	Rep(i, 0, V - 1)
		if (articulationVertex[i])
			printf(" Vertex %d\n", i);
#pragma endregion

#pragma region printing graph
	/*for (auto i = 0; i < V; i++)
	for (auto iter = adjlist[i].begin(); iter != adjlist[i].end(); ++iter)
	cout << iter->first << " " << iter->second << endl;*/
#pragma endregion 

	cin.get();
	return 0;
}
