#include <iostream>
using namespace std;
int arr[100005];
int st[400005];// È¦¼ö °³¼ö
void update(int index, int s, int e, int num) {
	if (num<s || num>e) {
		return;
	}
	if (s == e) {
		st[index] = arr[num] % 2;
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, num);
	update(index * 2 + 1, mid + 1, e, num);
	st[index] = st[index * 2] + st[index * 2 + 1];
}
int calc(int index, int s, int e, int l, int r) {
	if (e < l || r < s) {
		return 0;
	}
	if (l <= s && e <= r) {
		return st[index];
	}
	int mid = (s + e) / 2;
	return calc(index * 2, s, mid, l, r) + calc(index * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(1, 1, n, i);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1) {
			arr[a] = b;
			update(1, 1, n, a);
		}
		else if (flag == 2) {
			cout << b - a + 1 - calc(1, 1, n, a, b) << "\n";
		}
		else {
			cout << calc(1, 1, n, a, b) << "\n";
		}
	}
	return 0;
}