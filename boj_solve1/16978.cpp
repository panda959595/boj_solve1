#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long st[400005];
void update(int index, int s, int e, int i, int num) {
	if (i < s || e < i) {
		return;
	}
	if (s == e) {
		st[index] = num;
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, i, num);
	update(index * 2 + 1, mid + 1, e, i, num);
	st[index] = st[index * 2] + st[index * 2 + 1];
}
long long calc(int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return st[index];
	}
	int mid = (s + e) / 2;
	return calc(index * 2, s, mid, l, r) + calc(index * 2 + 1, mid + 1, e, l, r);
}
struct stru {
	int flag;
	int order;
	int a, b;
	int index;
};
bool compare(stru u, stru v) {
	return u.order * 10 + u.flag < v.order * 10 + v.flag;
}
vector<stru> query;
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
	int queryIndex = 1;
	for (int i = 0; i < m; i++) {
		int flag;
		int a, b, c;
		cin >> flag;
		if (flag == 1) {
			cin >> a >> b;
			query.push_back({ flag, queryIndex++, a, b , i });
		}
		else {
			cin >> a >> b >> c;
			query.push_back({ flag, a, b, c , i });
		}
	}
	sort(query.begin(), query.end(), compare);
	vector<pair<int, long long> > ans;
	for (auto k : query) {
		if (k.flag == 1) {
			update(1, 1, n, k.a, k.b);
		}
		else {
			long long temp = calc(1, 1, n, k.a, k.b);
			ans.push_back({ k.index, temp });
		}
	}
	sort(ans.begin(), ans.end());
	for (auto k : ans) {
		cout << k.second << "\n";
	}
	return 0;
}