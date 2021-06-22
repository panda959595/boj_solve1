#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > red;
vector<pair<int, int> > blue;
int parent[1005];
int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return parent[u] = find(parent[u]);
	}
}
int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return 0;
	}
	parent[u] = v;
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	while (1) {
		int count;
		cin >> n >> m >> k;
		if (n == 0) {
			break;
		}

		red.clear();
		blue.clear();
		
		for (int i = 0; i < m; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'R') {
				red.push_back({ a,b });
			}
			else {
				blue.push_back({ a,b });
			}
		}
		
		int minimum = 0;
		count = 0;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (auto k : red) {
			count += merge(k.first, k.second);
		}
		for (auto k : blue) {
			minimum += merge(k.first, k.second);
			if (count + minimum == n - 1) {
				break;
			}
		}
		if (count + minimum != n - 1) {
			cout << "0\n";
			continue;
		}

		int maximum = 0;
		count = 0;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (auto k : blue) {
			count += merge(k.first, k.second);
		}
		for (auto k : red) {
			maximum += merge(k.first, k.second);
			if (count + maximum == n - 1) {
				break;
			}
		}
		if (count + maximum != n - 1) {
			cout << "0\n";
			continue;
		}
		maximum = n - 1 - maximum;

		if (minimum <= k && k <= maximum) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
	return 0;
}