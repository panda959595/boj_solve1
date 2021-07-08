#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector< pair<int,long long> > road[100005];
vector< pair<int,long long> > child[100005];
int height[100005];
int parent[100005][20];
long long upCost[100005][20];
int findLCA(int u, int v) {
	if (height[u] != height[v]) {
		if (height[u] < height[v]) {
			int temp = u;
			u = v;
			v = temp;
		}
		for (int i = 19; i >= 0; i--) {
			if (height[parent[u][i]] > height[v]) {
				u = parent[u][i];
			}
		}
		u = parent[u][0];
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; i >= 0; i--) {
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}
long long calcUpCost(int u, int v) {
	if (u == v) {
		return 0;
	}
	long long ret = 0;
	for (int i = 19; i >= 0; i--) {
		if (height[parent[u][i]] > height[v]) {
			ret += upCost[u][i];
			u = parent[u][i];
		}
	}
	ret += upCost[u][0];
	return ret;
}
int moveUp(int u, int k) {
	if (k == 0) {
		return u;
	}
	int t = 20;
	int temp = 1 << 20;
	while (temp != 0) {
		if (temp < k) {
			u = parent[u][t];
			k -= temp;
		}
		temp /= 2;
		t--;
	}
	return parent[u][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	height[1] = 1;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 1; i < 20; i++) {
			parent[now][i] = parent[parent[now][i - 1]][i - 1];
			upCost[now][i] += upCost[now][i - 1] + upCost[parent[now][i - 1]][i - 1];
		}
		for (auto k : road[now]) {
			if (height[k.first] != 0) {
				continue;
			}
			child[now].push_back({ k.first,k.second });
			parent[k.first][0] = now;
			upCost[k.first][0] = k.second;
			height[k.first] = height[now] + 1;
			que.push(k.first);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int q;
		int u, v;
		cin >> q;
		if (q == 1) {
			cin >> u >> v;
			int p = findLCA(u, v);
			long long temp = calcUpCost(u, p) + calcUpCost(v, p);
			cout << temp << "\n";
		}
		else {
			int k;
			cin >> u >> v >> k;
			k--;
			int p = findLCA(u, v);
			if (height[u] - height[p] > k) {
				cout << moveUp(u, k) << "\n";
			}
			else if (height[u] - height[p] == k) {
				cout << p << "\n";
			}
			else {
				cout << moveUp(v, height[v] - height[p] - (k - (height[u] - height[p]))) << "\n";
			}
		}
	}
	return 0;
}