// Uva 10171 
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	int N, c;
	char age, dir, x, y, i1, i2;
	int adjmat[26][26];	
		
	int i = 0;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		map< pair<char, char>, char> cmp;
		
		for (auto i = 0; i < 26; ++i) 
			for (auto j = 0; j < 26; ++j) 
				adjmat[i][j] = 500;

		for (auto i = 0; i < N; ++i) {
			cin >> age >> dir >> x >> y >> c;	
			adjmat[x - 'A'][y - 'A'] = c;
			cmp[make_pair(x, y)] = age;
		}
		cin >> i1 >> i2;											
		for (auto k = 0; k < N; ++k) {
			for (auto i = 0; i < N; ++i) {
				for (auto j = 0; j < N; ++j) {
					adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
				}
			}
		}
		
		vector< pair<char, int> > p1;
		vector< pair<char, int> > p2;
		if (x == y)
			printf("0 %c \n", x);
		else {
			for (auto it = cmp.begin(); it != cmp.end(); ++it) {
				if (it->second == 'Y' && it->first.first == i1)
					p1.push_back(make_pair(it->first.second, adjmat[i1 - 'A'][it->first.second - 'A']));	
			}

			for (auto it = cmp.begin(); it != cmp.end(); ++it) {
				if (it->second == 'M' && it->first.first == i2)
					p2.push_back(make_pair(it->first.second, adjmat[i2 - 'A'][it->first.second - 'A']));
			}

			if (p1.empty() || p2.empty())
			printf("You will never meet. \n");
			else {
				sort(p1.begin(), p1.end());
				sort(p2.begin(), p2.end());

				for (auto it1 = p1.begin(), it2 = p2.begin(); it1 != p1.end(), it2 != p2.end(); ++it1, ++it2) {
					cout << it1->second + it2->second << " " << it1->first << endl;
				}
			}
		}		
	}
	cin.get();
	return 0;
}
