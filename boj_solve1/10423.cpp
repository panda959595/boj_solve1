#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1005];
int link[1005];
bool power[1005];
int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return parent[u] = find(parent[u]);
	}
}
struct stru {
	int s, e;
	int cost;
};
bool compare(stru u, stru v) {
	return u.cost < v.cost;
}
vector<stru> road;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	int cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		power[temp] = true;
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		link[i] = 1;
	}
	cnt += k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road.push_back({ a,b,c });
	}
	sort(road.begin(), road.end(), compare);
	int ans = 0;
	for (auto k : road) {
		int u = find(k.s);
		int v = find(k.e);
		if (u == v) {
			continue;
		}
		if (power[u] && power[v]) {
			continue;
		}
		if (power[u] && !power[v]) {
			parent[v] = u;
			link[u] += link[v];
			cnt += link[v];
		}
		else if (!power[u] && power[v]) {
			parent[u] = v;
			link[v] += link[u];
			cnt += link[u];
		}
		else {
			parent[v] = u;
			link[u] += link[v];
		}
		ans += k.cost;
		if (cnt == n) {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}