#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cassert>
using namespace std;

//#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

queue<int> q;
map<int, int> dist;	

bool MinSteps(int moves[], int N)
{
	q.push(0);
	dist[0] = 0;
	int u;

	while (!q.empty()) {
		u = q.front();
		q.pop();
		//printf("Visit %d, Layer %d\n", u, dist[u]);
		int v = u;
		if (v == N - 1)
			break;

		for (auto i = v + 1; i <= v + 6 && i < N; ++i){
			if (!dist.count(i) && !dist.count(moves[i])) {
				//assert(i == 2);
				if (moves[i] != -1) {
					dist[moves[i]] = dist[u] + 1;
				} else {
					dist[i] = dist[u] + 1;
				}
				q.push(i);	// enqueue v for next steps	
			}
		}
	}
	
	for (auto iter = dist.begin(); iter != dist.end(); ++iter) {
		cout << iter->first << " " << iter->second << endl;
	}
	cin.get();

	//	for (auto i = v + 1; i <= (v + 6) && i < N; ++i)
	//		if (!dist.count(i)) { // if v is not visited before and reachable from u
	//			/*int d;
	//			d = dist[v] + 1;				*/
	//			/*if (u == 21) {
	//				cout << "";
	//			}*/
	//			dist[u] = dist[u] + 1;

	//			if (move[i] != -1)
	//				u = move[i];
	//				else 
	//				u = i;
	//			q.push(u);	// enqueue v for next steps	
	//		}
	//}
	return dist[u];
}

int main()
{
	const int N = 30;
	int moves[N];

	memset(moves, -1, sizeof(moves));

	// Ladders
	//moves[0] = 29;
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout << MinSteps(moves, N);
	cin.get();
	return 0;
}
