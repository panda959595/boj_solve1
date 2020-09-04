#include <iostream>
#include <algorithm>
using namespace std;
int min_st[800005];
int max_st[800005];
int arr[200005];
int n, m;
void min_update(int index, int l, int r, int i, int num) {
	if (l > i || r < i) {
		return;
	}
	if (l == r) {
		min_st[index] = num;
		return;
	}
	int mid = (l + r) / 2;
	min_update(index * 2, l, mid, i, num);
	min_update(index * 2 + 1, mid + 1, r, i, num);
	min_st[index] = min(min_st[index * 2], min_st[index * 2 + 1]);
}
void max_update(int index, int l, int r, int i, int num) {
	if (l > i || r < i) {
		return;
	}
	if (l == r) {
		max_st[index] = num;
		return;
	}
	int mid = (l + r) / 2;
	max_update(index * 2, l, mid, i, num);
	max_update(index * 2 + 1, mid + 1, r, i, num);
	max_st[index] = max(max_st[index * 2], max_st[index * 2 + 1]);
}
int min_calc(int index, int l, int r, int s, int e) {
	if (s > r || e < l) {
		return n + 1;
	}
	if (l >= s && e >= r) {
		return min_st[index];
	}
	int mid = (l + r) / 2;
	return min(min_calc(index * 2, l, mid, s, e), min_calc(index * 2 + 1, mid + 1, r, s, e));
}
int max_calc(int index, int l, int r, int s, int e) {
	if (s > r || e < l) {
		return 0;
	}
	if (l >= s && e >= r) {
		return max_st[index];
	}
	int mid = (l + r) / 2;
	return max(max_calc(index * 2, l, mid, s, e), max_calc(index * 2 + 1, mid + 1, r, s, e));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
		min_update(1, 1, n, arr[i + 1], i + 1);
		max_update(1, 1, n, arr[i + 1], i + 1);
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			min_update(1, 1, n, arr[b], c);
			max_update(1, 1, n, arr[b], c);
			min_update(1, 1, n, arr[c], b);
			max_update(1, 1, n, arr[c], b);
			int temp = arr[b];
			arr[b] = arr[c];
			arr[c] = temp;
		}
		else {
			int s = min_calc(1, 1, n, b, c);
			int e = max_calc(1, 1, n, b, c);
			if (e - s == c - b) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}