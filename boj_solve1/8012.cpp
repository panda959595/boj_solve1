#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int parent[30005][30];
vector<int> child[30005];
vector<int> road[30005];
int level[30005];
int LCA(int u, int v) {
 	if (u == v) {
		return u;
	}
	if (level[u] < level[v]) {
		int temp = u;
		u = v;
		v = temp;
	}
	for (int i = 29; i >= 0; i--) {
		if (level[parent[u][i]] >= level[v]) {
			u = parent[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 29; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
		level[i + 1] = -1;
	}
	queue<int> que;
	que.push(1);
	level[1] = 1;
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i < 30; i++) {
			parent[now][i] = parent[parent[now][i - 1]][i - 1];
		}
		for (auto k : road[now]) {
			if (level[k] != -1) {
				continue;
			}
			parent[k][0] = now;
			level[k] = level[now] + 1;
			que.push(k);
		}
	}
	int m;
	int temp;
	int now = 1;
	cin >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		int p = LCA(now, temp);
		ans += level[now] + level[temp] - 2 * level[p];
		now = temp;
	}
	cout << ans << endl;
	return 0;
}