#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>
//#include <map>
//#include <string>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<vii> AdjList;

const int INF = numeric_limits<int>::max();
priority_queue< ii, vector<ii>, greater<ii> > pq;

//map<int, int> dist;	
//AdjList adjlist(30);

//#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

void MiceMaze(int s, vector<vii>& adjlist, vector<int>& dist)
{	
		int wuv, d, u, v;
		dist[s] = 0;
		pq.push(ii(0, s));

		while (!pq.empty()) {
			ii top = pq.top();
			d = top.first;
			u = top.second;
			pq.pop();

			if (d == dist[u]) {
				for (auto it = adjlist[u].begin(); it != adjlist[u].end(); ++it) {
					v = it->first;
					wuv = it->second;
						
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
	int n, N, M, E, T, a, b, t;
	cin >> n;
	cout << endl;
	
	while (n--) {
		cin >> N;
		cin >> E;
		cin >> T;
		cin >> M;
		
		AdjList adjlist(N + 1);
		vector<int> dist(M, INF);

		for (auto i = 1; i <= M; ++i) {
			cin >> a >> b >> t;
			adjlist[a].push_back(make_pair(b, t)); 
		}
		
		MiceMaze(E, adjlist, dist);

		int count = 0;
		for (auto it = 0; it < M; ++it) {
			if (dist[it] <= T)
				count++;
		}
		/*for (auto i = 0; i < N; ++i) {
			MiceMaze(i, adjlist, dist);
			
			if ((dist[E] != numeric_limits<int>::max()) && dist[E] <= T)
				count++;			
		}*/
			
		cout << count << endl << endl;
	}
	
	cin.get();
	cin.get();
	return 0;
}
