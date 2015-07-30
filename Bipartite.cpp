#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cassert>
#include <queue>
using namespace std;

#pragma region Graph DS
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<vii> AdjList;
#pragma endregion

#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

queue<int> q;
map<int, int> dist;	
AdjList adjlist(8);

//const enum Color { Red, Blue };

bool IsBipartite (int s)
{
	int color[8];
	memset(color, -1, sizeof(color));
	bool flag = true;

	q.push(s);
	dist[s] = 0;
	color[s] = 1;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		//printf("Visit %d, Layer %d\n", u, dist[u]);

		TRvii(adjlist[u], v) {		
			if (!dist.count(v->first) && color[v->first] == -1) { // if v is not visited before 
				color[v->first] = 1- color[u];
				dist[v->first] = dist[u] + 1; //reachable from u
				q.push(v->first);	// enqueue v for next steps				 						
			}

			if (dist.count(v->first) && color[v->first] == color[u]) {
 				flag = false;
				return flag;
			}
		}
	}
	return flag;
}

int main()
{	
	//memset(moves, -1, sizeof(moves));
#pragma region Undirected graph
	// Undirected graph
	/*adjlist[0].push_back(make_pair(1, 0));
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
	adjlist[7].push_back(make_pair(6, 0));*/
#pragma endregion

	// Colorable graph
	adjlist[0].push_back(make_pair(1, 0));
	adjlist[0].push_back(make_pair(2, 0));
	adjlist[1].push_back(make_pair(0, 0));
	adjlist[2].push_back(make_pair(0, 0));	
	adjlist[2].push_back(make_pair(4, 0));	
	adjlist[1].push_back(make_pair(3, 0));
	adjlist[3].push_back(make_pair(1, 0));
	adjlist[3].push_back(make_pair(5, 0));
	adjlist[4].push_back(make_pair(5, 0));	
	adjlist[4].push_back(make_pair(2, 0));	
	adjlist[5].push_back(make_pair(4, 0));
	adjlist[5].push_back(make_pair(3, 0));

	// non colorable graph
	/*adjlist[0].push_back(make_pair(1, 0));
	adjlist[0].push_back(make_pair(2, 0));
	adjlist[1].push_back(make_pair(0, 0));
	adjlist[2].push_back(make_pair(0, 0));	
	adjlist[2].push_back(make_pair(4, 0));	
	adjlist[1].push_back(make_pair(3, 0));
	adjlist[3].push_back(make_pair(1, 0));
	adjlist[3].push_back(make_pair(4, 0));
	adjlist[4].push_back(make_pair(3, 0));	
	adjlist[4].push_back(make_pair(2, 0));	*/


	bool flag = IsBipartite(0);
	cout << flag;
	cin.get();
	return 0;
}
