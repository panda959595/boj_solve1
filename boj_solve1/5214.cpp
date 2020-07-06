#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> tube[100005];
bool finish[1005];
bool road[1005][1005];
int cost[1005];
int main() {
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			tube[temp - 1].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < tube[i].size(); j++) {
			for (int k = 0; k < j; k++) {
				road[tube[i][j]][tube[i][k]] = road[tube[i][k]][tube[i][j]] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cost[i] = -1;
	}
	queue<int> que;
	for (auto k : tube[0]) {
		cost[k] = 0;
		que.push(k);
	}
	for (auto k : tube[n - 1]) {
		finish[k] = true;
	}
	int ans = -1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		if (finish[now]) {
			ans = cost[now] + 2;
			break;
		}
		for (int i = 0; i < m; i++) {
			if (road[now][i] && cost[i] == -1) {
				cost[i] = cost[now] + 1;
				que.push(i);
			}
		}
	}
	if (n == 1) {
		ans = 1;
	}
	cout << ans << endl;
	return 0;
}