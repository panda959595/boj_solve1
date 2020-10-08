#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100005];
vector<int> tree[400000];
void make_tree(int index, int s, int e) {
	if (s == e) {
		tree[index].push_back(arr[s]);
		return;
	}
	int mid = (s + e) / 2;
	make_tree(index * 2, s, mid);
	make_tree(index * 2 + 1, mid + 1, e);
	vector<int>::iterator i, j;
	i = tree[index * 2].begin();
	j = tree[index * 2 + 1].begin();
	while (i != tree[index * 2].end() || j != tree[index * 2 + 1].end()) {
		if (i == tree[index * 2].end()) {
			tree[index].push_back(*j);
			j++;
		}
		else if (j == tree[index * 2 + 1].end()) {
			tree[index].push_back(*i);
			i++;
		}
		else {
			if (*i > * j) {
				tree[index].push_back(*j);
				j++;
			}
			else {
				tree[index].push_back(*i);
				i++;
			}
		}
	}
}
int func(int index, int s, int e, int num) {
	vector<int>::iterator ite = upper_bound(tree[index].begin(), tree[index].end(), num);
	return tree[index].end() - ite;
}
int calc(int index, int s, int e, int l, int r, int num) {
	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return func(index, s, e, num);
	}
	int mid = (s + e) / 2;
	return calc(index * 2, s, mid, l, r, num) + calc(index * 2 + 1, mid + 1, e, l, r, num);
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
	make_tree(1, 1, n);
	cin >> m;
	int pre = 0;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a ^= pre;
		b ^= pre;
		c ^= pre;
		pre = calc(1, 1, n, a, b, c);
		cout << pre << "\n";
	}
	return 0;
}