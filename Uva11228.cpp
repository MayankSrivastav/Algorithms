// UVa 11228 - Transportation system

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

const int V = 7;
vector<int> pset(1000);
typedef pair<int, int> ii;
priority_queue< pair<int, ii> > edgeList;

void InitSet(int _size)
{
	pset.resize(_size);
	REP(i, 0, _size - 1)
		pset[i] = i;
}

// Union-Find Disjoint set 
int FindSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = FindSet(pset[i]));
}

void UnionSet(int i, int j)
{
	pset[FindSet(i)] = FindSet(j);
}

bool IsSameSet(int i, int j)
{
	return FindSet(i) == FindSet(j);
}

// Ksruskal's main funtion
void TransportSystem(int& r_cost, int& rr_cost, int r)
{		
	//int r_cost = 0, rr_cost = 0;
	InitSet(V); // initially all vertices in disjoint set

	while (!edgeList.empty()) {
		pair<int, ii> front = edgeList.top();
		edgeList.pop();

		if (!IsSameSet(front.second.first, front.second.second)) { // if no cycle, in the disjoint set
			//mst_cost += (-front.first);
			if (-front.first <= r)
				r_cost += (-front.first);
			else if (-front.first > r)
				rr_cost += (-front.first);

			UnionSet(front.second.first, front.second.second);
		}
	}
	//return mst_cost;
}

int main()
{
	int T, n, r, x, y, tot = 0;
	cin >> T;

	while (T--) {
		cin >> n >> r;
		
		pset.erase(pset.begin(), pset.end());
		vector<ii> d;

		for (auto i = 0; i < n; ++i) {
			cin >> x >> y;
			d.push_back(ii(x, y));
		}

		int xs, ys, sq;
		int states = 0;
		for (auto i = 0; i < d.size(); ++i) {
			for (auto j = 0; j < d.size(); ++j) {
				if (i != j) {
					xs = pow((d[j].first - d[i].first), 2);
					ys = pow((d[j].second - d[i].second), 2);
					sq = sqrt(xs + ys);
					edgeList.push(make_pair(-sq, ii(i, j)));

					if (sq <= r)
						states++;
				}
			}
		}

		//int res = TransportSystem();
		int r_cost = 0, rr_cost = 0;
		TransportSystem(r_cost, rr_cost, r);
		cout << "Case #" << ++tot << ": " << states << " " << r_cost << " " << rr_cost << endl;
	}
	
	cin.get();
	cin.get();
	return 0;
}
