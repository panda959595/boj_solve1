#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct road {
	int u, v, cost;
};
vector<road> vec;
bool compare(road a, road b) {
	return a.cost < b.cost;
}


int n, m;
int parent[100'005];
int findP(int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return parent[u] = findP(parent[u]);
	}
}
bool merge(int u, int v) {
	u = findP(u);
	v = findP(v);
	if (u == v) {
		return false;
	}

	parent[u] = v;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({ a, b, c });
	}

	sort(vec.begin(), vec.end(), compare);

	int a = 1, b = 2;

	int ans = 0;
	int cnt = 0;
	for (auto k : vec) {
		int u = k.u;
		int v = k.v;
		if (merge(u, v)) {
			v = findP(v);
			a = findP(a);
			b = findP(b);
			ans += k.cost;
			cnt++;
		}
		if (cnt == n - 2) {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}