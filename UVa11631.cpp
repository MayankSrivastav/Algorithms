#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// UVa 11631 - Dark Roads
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000);
typedef pair<int, int> ii;
priority_queue< pair<int, ii> > edgeList;

void InitSet(int __size)
{	
	pset.resize(__size);
	REP(i, 0, __size - 1)
		pset[i] = i;
}

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

int MinLightingCost(int m)
{
	int minCost = 0;
	InitSet(m);
	
	while (!edgeList.empty()) {
		pair<int, ii> front = edgeList.top();
		edgeList.pop();
		
		if (!IsSameSet(front.second.first, front.second.second)) {
			minCost += -(front.first);
			
			UnionSet(front.second.first, front.second.second);
		}
	}
	return minCost;
}

int main()
{
	int m = -1, n = -1, x, y, z;	
	while (true) {
		cin >> m >> n;
		
		if (m == 0 && n == 0)
			break;
			
		pset.erase(pset.begin(), pset.end());
		
		int totCost = 0;
		for (auto i = 0; i < n; ++i) {
			cin >> x >> y >> z;
			edgeList.push(make_pair(-z, ii(x, y)));
			edgeList.push(make_pair(-z, ii(y, x)));
			
			totCost += z;
		}		
		
		int minCost = MinLightingCost(m);
		cout << totCost - minCost << endl;		
	}
	
	cin.get();
	cin.get();
	return 0;
}
