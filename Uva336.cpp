#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<long, long> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

queue<int> q;
map<int, int> dist;

void FarNodes(AdjList &adjlist, int s)
{
	q.empty();
	dist.clear();

	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		TRvii(adjlist[u], v)
			if (!dist.count(v->first)) {
				dist[v->first] = dist[u] + 1;
				q.push(v->first);
			}
	}
}

int main()
{
	int nc;
	int count = 0;
	while (true) {
		cin >> nc;
		AdjList adjlist(1073741823);

		if (nc == 0) break;

		int s, e;
		for (auto i = 0; i < nc; ++i) {
			cin >> s >> e;
			adjlist[s].push_back(make_pair(e, 0));
			adjlist[e].push_back(make_pair(s, 0));
		}	
	
		int sn, ttl, nr = 0;
		while (true) {
			cin >> sn >> ttl;
			
			if (sn == 0 && ttl == 0) break;

			FarNodes(adjlist, sn);

			for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
				if ((iter->second) > ttl)
					nr++;
			}
			count++;
			cout << "Case " << count << ": " << nr << " nodes not reachable from node " << sn << " with TTL = " << ttl << endl;
			nr = 0;
			
		}
	}	
}
