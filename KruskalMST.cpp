// Kruskal's Algorithm
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
int KruskalMST()
{
	// Graph input
	for (auto i = 0; i < V; ++i) {
		edgeList.push(make_pair(-5, make_pair(1, 2)));
		edgeList.push(make_pair(-5, make_pair(2, 1)));

		edgeList.push(make_pair(-2, make_pair(2, 3)));
		edgeList.push(make_pair(-2, make_pair(3, 2)));

		edgeList.push(make_pair(-5, make_pair(1, 5)));
		edgeList.push(make_pair(-5, make_pair(5, 1)));

		edgeList.push(make_pair(-8, make_pair(3, 4)));
		edgeList.push(make_pair(-8, make_pair(4, 3)));

		edgeList.push(make_pair(-5, make_pair(1, 4)));
		edgeList.push(make_pair(-5, make_pair(4, 1)));

		edgeList.push(make_pair(-8, make_pair(4, 5)));
		edgeList.push(make_pair(-8, make_pair(5, 4)));
	}

	int mst_cost = 0;
	InitSet(V); // initially all vertices in disjoint set

	while (!edgeList.empty()) {
		pair<int, ii> front = edgeList.top();
		edgeList.pop();

		if (!IsSameSet(front.second.first, front.second.second)) { // if no cycle, in the disjoint set
			mst_cost += (-front.first);
			UnionSet(front.second.first, front.second.second);
		}
	}
	return mst_cost;
}

int main()
{
	cout << KruskalMST();
	cin.get();
	return 0;
}
