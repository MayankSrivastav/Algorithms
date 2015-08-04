#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
#include <functional>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

const int INF = numeric_limits<int>::max();

priority_queue< ii, vector<ii>, greater<ii> > pq;

void SSSP(int s, vector<vii>& adjlist, vector<int>& dist)
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
			for (auto it& : adjlist[u]) {
				v = it.first;
				wuv = it.second;

				if (dist[u] + wuv < dist[v]) {
					dist[v] = dist[u] + wuv;
					pq.push(ii(dist[v], v));
				}
			}
		}
	}
}

int main()
{
	int N, tot, n, m, s, t, s1, t1, w;
	cin >> N;
	tot = N;
	while (N > 0) {	
		N--;
		cin >> n >> m >> s >> t;
		AdjList adjlist(n);
		vector<int> dist(n, INF);

		for (auto i = 0; i < m; ++i) {
			cin >> s1 >> t1 >> w;

			adjlist[s1].push_back(make_pair(t1, w));
			adjlist[t1].push_back(make_pair(s1, w));

		}
		SSSP(s, adjlist,dist);
		if (dist[t] == numeric_limits<int>::max())
			cout << "Case #" << tot - N << ": " << "unreachable" << endl;
		else cout << "Case #" << tot - N << ": " << dist[t] << endl;		
	}
	cin.get();
	cin.get();
	return 0;
}
