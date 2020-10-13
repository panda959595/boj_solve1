#include <iostream>
using namespace std;
long long arr[5005][5005];
int n, m, q;
void update(int x, int y, int num) {
	for (int i = x; i <= n; i += i & -i) {
		for (int j = y; j <= m; j += j & -j) {
			arr[i][j] += num;
		}
	}
}
long long calc(int x, int y) {
	long long ret = 0;
	for (int i = x; i > 0; i -= i & -i) {
		for (int j = y; j > 0; j -= j & -j) {
			ret += arr[i][j];
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	while (q--) {
		int flag;
		cin >> flag;
		if (flag == 1) {
			int x1, x2, y1, y2, d;
			cin >> x1 >> y1 >> x2 >> y2 >> d;
			update(x1, y1, d);
			update(x2 + 1, y2 + 1, d);
			update(x1, y2 + 1, -d);
			update(x2 + 1, y1, -d);
		}
		else {
			int x, y;
			cin >> x >> y;
			cout << calc(x, y) << "\n";
		}
	}
	return 0;
}