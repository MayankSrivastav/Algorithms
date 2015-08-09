// Uva 11463

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

const int INF = 10000007;
int main()
{
	int T, N, R, u, v, s, d, tCount = 0;
	int adjmat[110][110];
	cin >> T;
	freopen("10171_out.txt", "w", stdout);
	while (T--) {		
		tCount++;

		//int adjmat[100][100] = { 0 };
		for (auto i = 0; i < 110; ++i)
			for (auto j = 0; j < 110; ++j) {
				if (i != j)
					adjmat[i][j] = INF;
				else adjmat[i][j] = 0;
			}				

		cin >> N;
		cin >> R;
		for (auto i = 0; i < R; i++) {
			cin >> u >> v;
			adjmat[u][v] = 1;
			adjmat[v][u] = 1;
		}

		cin >> s >> d;

		for (auto k = 0; k < N; ++k) {
			for (auto i = 0; i < N; ++i) {
				for (auto j = 0; j < N; ++j) {
					adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
				}					
			}
		}
		
		for (auto i = 0; i < N; ++i)
			adjmat[s][d] = adjmat[0][i] + adjmat[i][d];
		cout << "Case " << tCount << ": " << adjmat[s][d] << endl;		
	}

	cin.get();
	cin.get();
	return 0;
}
