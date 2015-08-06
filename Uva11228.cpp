// UVa 11228 - Transportation system

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
vector<int> pset(1000);
typedef pair<double, double> ii;
priority_queue< pair<double, ii> > edgeList;

void InitSet(int _size)
{
	pset.resize(_size);
	REP(i, 0, _size - 1)
		pset[i] = i;
}

// Union-Find Disjoint set 
int FindSet(double i)
{
	return (pset[i] == i) ? i : (pset[i] = FindSet(pset[i]));
}

void UnionSet(double i, double j)
{
	pset[FindSet(i)] = FindSet(j);
}

bool IsSameSet(double i, double j)
{
	return FindSet(i) == FindSet(j);
}

// Ksruskal's main funtion
int TransportSystem(double& r_cost, double& rr_cost, int r, int n)
{		
	//int r_cost = 0, rr_cost = 0;
	int states = 1;
	InitSet(n); // initially all vertices in disjoint set

	while (!edgeList.empty()) {
		pair<double, ii> front = edgeList.top();
		edgeList.pop();

		if (!IsSameSet(front.second.first, front.second.second)) { // if no cycle, in the disjoint set
			//mst_cost += (-front.first);
			if (-front.first <= r)
				r_cost += (-front.first);
			else if (-front.first > r) {
				rr_cost += (-front.first);
				states++;
			}

			UnionSet(front.second.first, front.second.second);
		}
	}
	return states;
}

int main()
{
	int T, n, r, tot = 0;
	double x, y;
	cin >> T;

	while (T--) {
		cin >> n >> r;
		
		pset.erase(pset.begin(), pset.end());
		vector<ii> d;

		for (auto i = 0; i < n; ++i) {
			cin >> x >> y;
			d.push_back(ii(x, y));
		}

		double xs, ys, sq;		
		for (auto i = 0; i < d.size(); ++i) {
			for (auto j = 0; j < d.size(); ++j) {
				if (i != j) {
					xs = pow((d[j].first - d[i].first), 2);
					ys = pow((d[j].second - d[i].second), 2);
					
					/********************************** Debug**************************************/
					/*double sqq = sqrt(xs + ys);
					cout << endl << sqq;
					cin.get();*/

					/******************************************************************************/
					//sq = sqrt(xs + ys) < 0.0 ? ceil(sqrt(xs + ys) - 0.5) : floor(sqrt(xs + ys) + 0.5);
					sq = sqrt(xs + ys); //< 0.0 ? static_cast<int>(sqrt(xs + ys) - 0.5) : static_cast<int>(sqrt(xs + ys) + 0.5);
					edgeList.push(make_pair(-sq, ii(i, j)));
				}
			}
		}

		//int res = TransportSystem();
		double r_cost = 0, rr_cost = 0;
		int states = TransportSystem(r_cost, rr_cost, r, n);
		r_cost = static_cast<int>(r_cost + 0.5);
		rr_cost = static_cast<int>(rr_cost + 0.5);

		cout << "Case #" << ++tot << ": " << states << " " << r_cost << " " << rr_cost << endl;
	}
	
	cin.get();
	cin.get();
	return 0;
}
