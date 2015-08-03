// Dijkstra's Single source shortest path algorithm

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <limits>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

const int V = 100;
//const double INF = numeric_limits<double>::infinity();
const double INF = numeric_limits<int>::max();
#define TRVii(c, it) for (vii::iterator it = c.begin(); it != c.end(); ++it)

vector<int> dist(V, INF);
priority_queue<ii, vector<ii>, greater<ii> > pq;
AdjList adjlist(V);

void SSSP(int s)
{
	int wuv, d, u, v;
	dist[s] = 0;
	pq.push(ii(0, s));

	while (!pq.empty()) {
		ii top = pq.top();
		pq.pop();
		d = top.first;
		u = top.second;

		if (d == dist[u]) {
			TRVii(adjlist[u], it) {
				v = it->first;
				wuv = it->second;
				if (dist[u] + wuv < dist[v]) { // if can be relaxed
					dist[v] = dist[u] + wuv; // relax
					pq.push(ii(dist[v], v));	// enqueue this neighbour, regardless of it's already there
				}
			}
		}
	}
}

int main()
{
	adjlist[1].push_back(make_pair(3, 3));	
	adjlist[1].push_back(make_pair(4, 6));
	adjlist[2].push_back(make_pair(1, 2));
	adjlist[2].push_back(make_pair(3, 7));
	adjlist[2].push_back(make_pair(5, 6));
	adjlist[3].push_back(make_pair(4, 5));	
	adjlist[5].push_back(make_pair(4, 1));

	int s = 2;
	SSSP(s);

	for (auto iter = 1; iter <= 5; ++iter)  {
		if (iter != s)
			cout << dist[iter] << " ";
	}
	cin.get();
	return 0;
}
