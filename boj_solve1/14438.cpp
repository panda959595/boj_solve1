#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_NUM = 9876543210;
int st[400000];
void update(int index, int s, int e, int i, int k) {
	if (i < s || e < i) {
		return;
	}
	if (s == e) {
		st[index] = k;
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, i, k);
	update(index * 2 + 1, mid + 1, e, i, k);
	st[index] = min(st[index * 2], st[index * 2 + 1]);
}
int calc(int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return MAX_NUM;
	}
	if (l <= s && e <= r) {
		return st[index];
	}
	int mid = (s + e) / 2;
	return min(calc(index * 2, s, mid, l, r), calc(index * 2 + 1, mid + 1, e, l, r));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		update(1, 1, n, i, temp);
	}
	cin >> m;
	while (m--) {
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1) {
			update(1, 1, n, a, b);
		}
		else {
			cout << calc(1, 1, n, a, b) << "\n";
		}
	}
	return 0;
}