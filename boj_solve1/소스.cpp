#include <iostream>
#include <vector>
using namespace std;
int segTree[8005];
vector<int> road[2005];
void update(int index, int s, int e, int num) {
	if (num < s || e < num) {
		return;
	}
	segTree[index]++;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, num);
	update(index * 2 + 1, mid + 1, e, num);
}
int calc(int index, int s, int e, int l, int r) {
	if (l <= s && e <= r) {
		return segTree[index];
	}
	else if (r < s || e < l) {
		return 0;
	}
	int mid = (s + e) / 2;
	return calc(index * 2, s, mid, l, r) + calc(index * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (auto j : road[i]) {
			ans += calc(1, 1, n, j + 1, n);
		}
		for (auto j : road[i]) {
			update(1, 1, n, j);
		}
	}
	cout << ans << "\n";
	return 0;
}