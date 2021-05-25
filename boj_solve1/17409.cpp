#include <iostream>
using namespace std;
const int divNum = 1000000007;
int st[11][400000];// [a][b] 길이 a인 증가수열
void update(int len, int index, int s, int e, int idx, int num) {
	if (idx < s || e < idx) {
		return;
	}
	st[len][index] += num;
	st[len][index] %= divNum;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(len, index * 2, s, mid, idx, num);
	update(len, index * 2 + 1, mid + 1, e, idx, num);
}
int calc(int len, int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return st[len][index];
	}
	int mid = (s + e) / 2;
	return (calc(len, index * 2, s, mid, l, r) + calc(len, index * 2 + 1, mid + 1, e, l, r)) % divNum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		update(1, 1, 1, n, temp, 1);
		for (int j = 2; j <= k; j++) {
			int tmp = calc(j - 1, 1, 1, n, 1, temp - 1);
			update(j, 1, 1, n, temp, tmp);
		}
	}
	cout << st[k][1] << "\n";
	return 0;
}