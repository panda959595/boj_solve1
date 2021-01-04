#include <iostream>
using namespace std;
int arr[100005];
int st[400005];
void make_st(int index, int l, int r) {
	if (l == r) {
		st[index] = l;
		return;
	}
	int mid = (l + r) / 2;
	make_st(index * 2, l, mid);
	make_st(index * 2 + 1, mid + 1, r);
	if (arr[st[index * 2]] > arr[st[index * 2 + 1]]) {
		st[index] = st[index * 2 + 1];
	}
	else {
		st[index] = st[index * 2];
	}
}
void update(int index, int l, int r, int idx) {
	if (idx<l || idx>r) {
		return;
	}
	if (l == r) {
		st[index] = l;
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, idx);
	update(index * 2 + 1, mid + 1, r, idx);
	if (arr[st[index * 2]] > arr[st[index * 2 + 1]]) {
		st[index] = st[index * 2 + 1];
	}
	else {
		st[index] = st[index * 2];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make_st(1, 1, n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			int a, b;
			cin >> a >> b;
			arr[a] = b;
			update(1, 1, n, a);
		}
		else {
			cout << st[1] << "\n";
		}
	}
	return 0;
}