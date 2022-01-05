#include <iostream>
using namespace std;
int st[400005];
int arr[100005];
int gift[100005];
void update(int index, int s, int e, int num, int value) {
	if (num < s || e < num) {
		return;
	}
	st[index] += value;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, num, value);
	update(index * 2 + 1, mid + 1, e, num, value);
}
int findST(int index, int s, int e, int num) {
	if (s == e) {
		return s;
	}
	int left = st[index * 2];
	int mid = (s + e) / 2;
	if (left < num) {
		return findST(index * 2 + 1, mid + 1, e, num - left);
	}
	else {
		return findST(index * 2, s, mid, num);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		update(1, 1, 100000, temp + 1, 1);
	}
	for (int i = 0; i < m; i++) {
		cin >> gift[i];
	}
	int answer = 1;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		int num = findST(1, 1, 100000, n - temp + 1);
		if (gift[i] + 1 > num) {
			answer = 0;
			break;
		}
		update(1, 1, 100000, num, -1);
		update(1, 1, 100000, num - gift[i], 1);
	}
	cout << answer << "\n";
	return 0;
}