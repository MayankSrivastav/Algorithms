#pragma region ADJLIST
// * Adjacency List for
// * Directed Weighted Graph
// * Code using C++ STL
// 
// 
// 
//#include <cstdio>
//#include <vector>
//#include <list>
//#include <utility>
// 
//using namespace std;
// 
//int main()
//{
//    int vertices, edges, v1, v2, weight;
//     
//    printf("Enter the Number of Vertices -\n");
//    scanf("%d", &vertices);
//     
//    printf("Enter the Number of Edges -\n");
//    scanf("%d", &edges);
//     
//    // Adjacency List is a vector of list.
//    // Where each element is a pair<int, int>
//    // pair.first -> the edge's destination
//    // pair.second -> edge's weight
//    vector< list< pair<int, int> > > adjacencyList(vertices + 1);
//     
//    printf("Enter the Edges V1 -> V2, of weight W\n");
//     
//    for (int i = 1; i <= edges; ++i) {
//        scanf("%d%d%d", &v1, &v2, &weight);
//         
//        // Adding Edge to the Directed Graph
//        adjacencyList[v1].push_back(make_pair(v2, weight));
//    }
//     
//    printf("\nThe Adjacency List-\n");
//    // Printing Adjacency List
//    for (int i = 1; i < adjacencyList.size(); ++i) {
//        printf("adjacencyList[%d] ", i);
//         
//        list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
//         
//        while (itr != adjacencyList[i].end()) {
//            printf(" -> %d(%d)", (*itr).first, (*itr).second);
//            ++itr;
//        }
//        printf("\n");
//    }
//	getchar();
//    return 0;
//}
#pragma endregion


#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<vii> AdjList;

queue<int> q;
map<int, int> dist;	
AdjList adjlist(30);

#define TRvii(c, it) for (vii::iterator it = c.begin(); it != c.end(); it++)

long Legs(int s, int d)
{	
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

int main()
{
	printf("SHIPPING ROUTES OUTPUT\n");
	int ds, m, n, p, arr[26][26] = {-1};
	cin >> ds;
	int tot = ds;
	while (ds > 0) {
		ds--;
		adjlist.empty();

		printf("DATA SET %d\n", tot - ds);
		cin >> m >> n >>p;
		
		string wh;
		for (int i = 0; i < m; ++i) {
			cin >> wh;
			arr[wh[0] - 'A'][wh[1] - 'B'] = i;
		}

		string legL, legR;
		int index;
		for (int j = 0; j < n; ++j) {
			cin >> legL >> legR;
			//index = arr[legL[0] - 'A'][legL[1] - 'A'];
			adjlist[arr[legL[0] - 'A'][legL[1] - 'A']].push_back(make_pair(arr[legR[0] - 'A'][legR[1] - 'A'], 0));
			adjlist[arr[legR[0] - 'A'][legR[1] - 'A']].push_back(make_pair(arr[legL[0] - 'A'][legL[1] - 'A'], 0));
		}

		int size;
		string qa, qb;
		for (int k = 0; k < p; ++k) {
			cin >> size >> qa >> qb;

			int res = Legs(arr[qa[0] - 'A'][qa[1] - 'A'], arr[qb[0] - 'A'][qb[1] - 'A']);
			if (res >= 0)
				cout << "$" << (size * res * 100) << endl;
			else cout << "NO SHIPMENT POSSIBLE" << endl;
		}
	}

	cout << "END OF OUTPUT";
	cin.get();
	return 0;
}
