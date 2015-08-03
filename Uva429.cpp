#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <chrono>
#include <sstream>

using namespace std;

//#define _CRT_SECURE_NO_DEPRECATE

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> AdjList;

queue<int> q;
map<int, int> dist;
//AdjList adjlist(30);

#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

long Steps(int s, int d, vector<vii>& adjlist)
{
	dist.clear();
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == d)
			return dist[u];

		TRvii(adjlist[u], v)
			if (!dist.count(v->first)) {
				dist[v->first] = dist[u] + 1;
				q.push(v->first);
			}
	}
	return -1;
}

bool Count(string a, string b)
{
	int c = 0;
	for (auto i = 0; i < a.length(); ++i) {
		if (!(a[i] == b[i]))
			c++;
	}
	if (c <= 1)
		return true;
	else return false;
}

int main()
{	
	int n;
	map<string, int> mp;
	cin >> n;
	int tot = n;
	while (n > 0) {
		cout << endl;
		n--;
		AdjList adjlist(220);
		mp.clear();
		
		string w;
		int i = 0;
		while (true) {			
			cin >> w;
			if (w == "*") break;
				
			mp[w] = i;
			i++;
		}	
		cout << endl;

		for (auto i = mp.begin(); i != mp.end(); ++i) {
			for (auto j = i; j != mp.end(); ++j) {				
				if (i->first != j->first && i->first.length() == j->first.length()) {
					if (Count(i->first, j->first)) {
						adjlist[i->second].push_back(make_pair(j->second, 0));
						adjlist[j->second].push_back(make_pair(i->second, 0));
					}
				}											
			}
		}

		char s1[10], s2[10];
		string p1, p2;
		//pair<string, string> s;
		string in;
		/*typedef std::chrono::high_resolution_clock Clock;
		typedef std::chrono::milliseconds milliseconds;*/
		
		getline(cin, in);
		while (getline(cin, in)) {			
			if (!in[0]) break;

			stringstream iss(in);
			iss >> p1 >> p2;
			/*cin >> p1;			
			cin >> p2;*/
			//Clock::time_point t0 = Clock::now();
			auto iter1 = mp.find(p1);
			auto iter2 = mp.find(p2);
			if (iter1 != mp.end() && iter2 !=mp.end()) {
				int res = Steps(mp[p1], mp[p2], adjlist);
				cout << p1 << " " << p2 << " " << res << endl;
			} else cout << p1 << " " << p2 << " " << "-1" << endl;
			

			/*Clock::time_point t1 = Clock::now();
			milliseconds ms = std::chrono::duration_cast<milliseconds>(t1 - t0);
			std::cout << ms.count() << "ms\n";*/
		}
		/*cout << endl;*/
	}
	
	cin.get();
	cin.get();
	return 0;
}
