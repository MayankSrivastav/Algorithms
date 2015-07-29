// Algorithms on Graph data structure
	
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

#pragma region Graph DS
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<vii> AdjList;
#pragma endregion

#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int V = 8;
const int DFS_BLACK = 1;
const int DFS_WHITE = -1;

// Global variables and objects
int dfs_num[V];
int dfs_low[V];
int dfs_parent[V];
bool articulationVertex[V];
int dfs_root = 0;
int rootChildren = 0;
int dfsNumberCounter = 0;
AdjList adjlist(8);
stack<int> topologicalSort;
bool isCyclic = false;
queue<int> q;
map<int, int> dist;	

// Normal DFS, Directed graph Cycle find
// Undirected Graph Connected component 
// Directed graph strongly connected component
bool dfs(int u) 
{ // DFS for normal usage
	printf(" %d", u); 
	dfs_num[u] = DFS_BLACK; // this vertex is visited, mark it
	//TRvii (adjlist[u], v) // try all neighbors v of vertex u
	for (vii::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
		if (dfs_num[it->first] == DFS_WHITE) // avoid cycle
			dfs(it->first); // v is a (neighbor, weight) pair
		else isCyclic = true;
	}
	//topologicalSort.push_back(u);
	//topologicalSort.push(u);
	return isCyclic;
}

// Undirected graph Cycle find
bool dfs(int u, int parent) 
{ // DFS for normal usage
	printf(" %d", u); 
	dfs_num[u] = DFS_BLACK; // this vertex is visited, mark it
	//TRvii (adjlist[u], v) // try all neighbors v of vertex u
	for (vii::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
		if (dfs_num[it->first] == DFS_WHITE) // avoid cycle
			dfs(it->first); // v is a (neighbor, weight) pair
		else  if (it->first != parent) return isCyclic = true;
		else return isCyclic = false;
	}
	//topologicalSort.push_back(u);
	//topologicalSort.push(u);
	//return isCyclic;
}

// BFS
void BFS(int s)
{
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		printf("Visit %d, Layer %d\n", u, dist[u]);

		TRvii(adjlist[u], v)		
			if (!dist.count(v->first)) { // if v is not visited before and reachable from u
				dist[v->first] = dist[u] + 1;
				q.push(v->first);	// enqueue v for next steps	
			}
	}
}

// Articulation point and Bridge finding
void ArticulationPointAndBridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
	TRvii(adjlist[u], v)
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
	int numComponent = 0;

#pragma region Directed graph
	//adjlist[0].push_back(make_pair(1, 0));
	////adjlist[1].push_back(make_pair(2, 0));
	////adjlist[1].push_back(make_pair(0, 0));
	//adjlist[1].push_back(make_pair(3, 0));
	//adjlist[2].push_back(make_pair(1, 0));
	////adjlist[2].push_back(make_pair(3, 0));
	////adjlist[3].push_back(make_pair(1, 0));
	//adjlist[3].push_back(make_pair(2, 0));
	//adjlist[3].push_back(make_pair(4, 0));
	//adjlist[4].push_back(make_pair(5, 0));
	//adjlist[5].push_back(make_pair(7, 0));
	//adjlist[6].push_back(make_pair(4, 0));
	//adjlist[7].push_back(make_pair(6, 0));
#pragma endregion

#pragma region Undirected graph
	// Undirected graph
	adjlist[0].push_back(make_pair(1, 0));
	adjlist[1].push_back(make_pair(2, 0));
	adjlist[1].push_back(make_pair(0, 0));
	adjlist[1].push_back(make_pair(3, 0));
	adjlist[2].push_back(make_pair(1, 0));
	adjlist[2].push_back(make_pair(3, 0));	
	adjlist[3].push_back(make_pair(2, 0));
	adjlist[3].push_back(make_pair(4, 0));
	adjlist[4].push_back(make_pair(3, 0));
	adjlist[5].push_back(make_pair(5, 0));
	adjlist[6].push_back(make_pair(7, 0));
	adjlist[7].push_back(make_pair(6, 0));
#pragma endregion

	// initialize the dfs_num array with -1
	memset(dfs_num, DFS_WHITE, sizeof dfs_num);

#pragma region Topological Sort
	// Topological Sorting

	//REP(i, 0, V - 1)
	//	if (dfs_num[i] == DFS_WHITE)
	//		dfs(i);
	////reverse(topologicalSort.begin(), topologicalSort.end());
	//REP(i, 0, V - 1) {
	//	//cout << endl << topologicalSort.pop();
	//	printf ("%d\n", topologicalSort.top());
	//	topologicalSort.pop();
	//}
#pragma endregion

	// Normal dfs
	//dfs(3);

	// Normal BFS

	BFS(0);

	// Directed graph Cycle find
	/*if (dfs(0) == true)
		cout << endl << "true";*/
	
	// Undirected graph Cycle find
	// Overloaded with parent
	/*if (dfs(5, -1)) 
		cout << endl << "true";
	else cout << endl << "false";*/

	// Connected  component
	/*REP (i, 0, V - 1)
		if (dfs_num[i] == DFS_WHITE) {
			printf("Component %d, visit:", ++numComponent);
			dfs(i);
			printf("\n");
		}
	printf("There are %d connected components\n", numComponent);*/

	#pragma region Articulation Point
	// Find Articulation point
	//dfsNumberCounter = 0;
	//memset(dfs_num, DFS_WHITE, sizeof(dfs_num));
	//printf("Bridges: \n");
	//REP(i, 0, V - 1)
	//	if (dfs_num[i] == DFS_WHITE) {
	//		dfs_root = i;
	//		rootChildren = 0;
	//		ArticulationPointAndBridge(i);
	//		articulationVertex[dfs_root] = (rootChildren > 1); // special case
	//	}

	//printf("Articulation Ponints:\n");
	//REP(i, 0, V - 1)
	//	if (articulationVertex[i])
	//		printf(" Vertex %d\n", i);
#pragma endregion

	cin.get();	
	return 0;
}
