// Uva 10171 
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <numeric>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int N, c;
	char age, dir, x, y, i1, i2;
	int adjmatM[26][26], adjmatY[26][26];	
	
	freopen("10171_out.txt", "w", stdout);
	int i = 0;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		map< pair<char, char>, char> cmp;

		for (auto i = 0; i < 26; ++i)
			for (auto j = 0; j < 26; ++j) {
				adjmatM[i][j] = 500;
				adjmatY[i][j] = 500;
			}

		// for M class and Y class 
		for (auto i = 0; i < N; ++i) {
			cin >> age >> dir >> x >> y >> c;
			if (age == 'M') {
				adjmatM[x - 'A'][y - 'A'] = c;
				cmp[make_pair(x, y)] = age;

				if (dir == 'B') {
					adjmatM[y - 'A'][x - 'A'] = c;
					cmp[make_pair(y, x)] = age;
				}
			}
			else if (age == 'Y') {
				adjmatY[x - 'A'][y - 'A'] = c;
				cmp[make_pair(x, y)] = age;

				if (dir == 'B') {
					adjmatY[y - 'A'][x - 'A'] = c;
					cmp[make_pair(y, x)] = age;
				}
			}
		}
		cin >> i1 >> i2;
		for (auto k = 0; k < 26; ++k) {
			for (auto i = 0; i < 26; ++i) {
				for (auto j = 0; j < 26; ++j) {
					if (i == j) {
						adjmatM[i][j] = 0;
						adjmatY[i][j] = 0;
					}
					else {
						adjmatM[i][j] = min(adjmatM[i][j], adjmatM[i][k] + adjmatM[k][j]);
						adjmatY[i][j] = min(adjmatY[i][j], adjmatY[i][k] + adjmatY[k][j]);
					}					
				}
			}
		}

		vector< pair<int, char> > p1;
		vector< pair<int, char> > p2;
		if (i1 == i2)
			printf("0 %c \n", i1);
		else {
			for (auto i = 0; i < 26; ++i) {
				for (auto j = 0; j < 26; ++j) {
					if ((i == i1 - 'A' && j == i2 - 'A') || (i == i2 - 'A' && j == i1 - 'A')) {
						/*if (cmp[i1 - 'A'][i2 - 'A'] == 'M' && adjmatM[i][j] != 0 && adjmatM[i][j] < 500) {
							if (cmp[i1 - 'A'][i2 - 'A'] == Y)
						}*/
						continue;
					}
					 if (i == i1 - 'A') {
						if (adjmatM[i][j] < 500 && adjmatM[i][j] != 0 && (adjmatM[i2 - 'A'][j] < 500 || adjmatY[i2 - 'A'][j] < 500))
							p1.push_back(make_pair(adjmatM[i][j], 'A' + j));
						else if (adjmatY[i][j] < 500 && adjmatY[i][j] != 0 && (adjmatY[i2 - 'A'][j] < 500 || adjmatM[i2 - 'A'][j] < 500))
							p2.push_back(make_pair(adjmatY[i][j], 'A' + j));
					}
					else if (i == i2 - 'A') {
						if (adjmatM[i][j] < 500 && adjmatM[i][j] != 0 && (adjmatM[i1 - 'A'][j] < 500 || adjmatY[i1 - 'A'][j] < 500))
							p1.push_back(make_pair(adjmatM[i][j], 'A' + j));
						else if (adjmatY[i][j] < 500 && adjmatY[i][j] != 0 && (adjmatY[i1 - 'A'][j] < 500 || adjmatM[i1 - 'A'][j] < 500))
							p2.push_back(make_pair(adjmatY[i][j], 'A' + j));
					}
				}
			}
		}
		
		if (p1.empty() && p2.empty())
			cout << "You will never meet." << endl;
		else {
			sort(p1.begin(), p1.end());
			sort(p2.begin(), p2.end());

			for (auto it1 = p1.begin(), it2 = p2.begin(); it1 != p1.end(), it2 != p2.end(); ++it1, ++it2)
				cout << it1->first + it2->first << " " << it1->second << endl;
		}		
	}
	
	cin.get();
	return 0;
}
