#include <iostream>
using namespace std;
int n, m;
long long arr[1025][1025];
long long tree[1025][1025];
long long calc(int x, int y) {
	long long ret = 0;
	while (x > 0) {
		int temp = y;
		while (temp > 0) {
			ret += tree[x][temp];
			temp -= (temp & -temp);
		}
		x -= (x & -x);
	}
	return ret;
}
void update(int x, int y, long long num) {
	while (x<=n) {
		int temp = y;
		while (temp <= n) {
			tree[x][temp] += num;
			temp += (temp & -temp);
		}
		x += (x & -x);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int w, x1, y1, x2, y2;
		cin >> w;
		if (w == 0) {
			cin >> x1 >> y1 >> x2;
			update(x1, y1, x2 - arr[x1][y1]);
			arr[x1][y1] = x2;
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << calc(x2, y2) - calc(x1 - 1, y2) - calc(x2, y1 - 1) + calc(x1 - 1, y1 - 1) << "\n";
		}
	}
	return 0;
}