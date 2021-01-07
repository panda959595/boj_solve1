#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct stru {
	int destination;
	int cost;
};
vector<stru> road[20005];
int check[20005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	int s;
	cin >> v >> e >> s;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}
	for (int i = 1; i <= v; i++) {
		check[i] = 1987654321;
	}
	check[s] = 0;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (check[now.second] < now.first) {
			continue;
		}
		for (auto k : road[now.second]) {
			if (now.first + k.cost < check[k.destination]) {
				check[k.destination] = now.first + k.cost;
				pq.push({ check[k.destination],k.destination });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (check[i] == 1987654321) {
			cout << "INF\n";
		}
		else {
			cout << check[i] << "\n";
		}
	}

	return 0;
}