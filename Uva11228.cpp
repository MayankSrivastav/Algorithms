#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// UVa 11228 - Transportation System

typedef pair<int, int> ii;
priority_queue< pair<int, ii> > edgeList;
vector<int> pset(1000);

void Init_Set(int __size)
{
	pset.resize(__size);
	for (auto i = 0; i < __size; ++i) 
		pset[i] = i;
}

int FindSet(int i)
{
	return (pset[i] == i ? i : FindSet(pset[i]));	
}

void UnionSet(int i, int j)
{
	pset[FindSet(i)] = FindSet(j));
}

bool IsSameSet(int i, int j)
{
	return FindSet(i) == FindSet(j);
}



int main()
{
	int T, n, r, x, y;
	cin >> T;

	while (T--) {
		cin >> n >> r;
		pset.erase();
		
		for (auto i = 0; i < n; ++i) {
			cin >> x >> y;
		}
		TransportSystem();
		
	}
}
