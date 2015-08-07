// Uva 10171 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	char age, dir, x, y, c, i1, i2;
	int adjmat[1000][1000];

	while (true) {
		cin >> N;
		if (N == 0)
			break;
		
		cin >> age >> dir >> x >> y >> c;
		
		// initialize the matrix
		memset(adjmat, -1, sizeof(adjmat[0][0] * 1000 * 1000));

		for (auto k = 0; k < N; ++k) {
			for (auto i = 0; i < N; ++i) {
				for (auto j = 0; j < N; ++j) {
					adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
				}
			}
		}
		printf("%d", adjmat[])
	}

	return 0;
}
