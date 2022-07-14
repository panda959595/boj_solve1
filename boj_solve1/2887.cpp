#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru{
	int a, b;
	int num;
};
vector<stru> vec;
vector<stru> x;
vector<stru> y;
vector<stru> z;
bool compare(stru u, stru v) {
	return u.num < v.num;
}

int parent[100'005];
int s[100'005];
int findP(int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return parent[u] = findP(parent[u]);
	}
}
void merge(int u, int v) {
	if (u == v) {
		return;
	}
	parent[v] = u;
	s[u] += s[v];
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ i, 0, a });
		y.push_back({ i, 0, b });
		z.push_back({ i, 0, c });
		parent[i] = i;
		s[i] = 1;
	}
	sort(x.begin(), x.end(), compare);
	sort(y.begin(), y.end(), compare);
	sort(z.begin(), z.end(), compare);

	for (int i = 0; i < n - 1; i++) {
		vec.push_back({ x[i].a, x[i + 1].a, abs(x[i].num - x[i + 1].num) });
		vec.push_back({ y[i].a, y[i + 1].a, abs(y[i].num - y[i + 1].num) });
		vec.push_back({ z[i].a, z[i + 1].a, abs(z[i].num - z[i + 1].num) });
	}

	sort(vec.begin(), vec.end(), compare);

	int ans = 0;
	for (auto k : vec) {
		int u = findP(k.a);
		int v = findP(k.b);
		if (u == v) {
			continue;
		}
		merge(u, v);
		ans += k.num;
		if (s[u] == n) {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}