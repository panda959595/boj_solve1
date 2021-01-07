#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> st[400005];
void update(int index, int s, int e, int i, int num) {
	if (i < s || e < i) {
		return;
	}
	if (s == e) {
		st[index].first = num;
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, i, num);
	update(index * 2 + 1, mid + 1, e, i, num);
	vector<int> vec;
	vec.push_back(st[index * 2].first);
	vec.push_back(st[index * 2].second);
	vec.push_back(st[index * 2 + 1].first);
	vec.push_back(st[index * 2 + 1].second);
	sort(vec.begin(), vec.end());
	vector<int>::iterator ite = vec.end() - 1;
	st[index].first = *ite;
	ite--;
	st[index].second = *ite;
}
pair<int, int> calc(int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return make_pair(0, 0);
	}
	if (l <= s && e <= r) {
		return st[index];
	}
	vector<int> vec;
	pair<int, int> temp;
	int mid = (s + e) / 2;
	temp = calc(index * 2, s, mid, l, r);
	vec.push_back(temp.first);
	vec.push_back(temp.second);
	temp = calc(index * 2 + 1, mid + 1, e, l, r);
	vec.push_back(temp.first);
	vec.push_back(temp.second);
	sort(vec.begin(), vec.end());
	vector<int>::iterator ite = vec.end() - 1;
	temp.first = *ite;
	ite--;
	temp.second = *ite;
	return temp;
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
	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1) {
			update(1, 1, n, a, b);
		}
		else {
			pair<int, int> temp = calc(1, 1, n, a, b);
			cout << temp.first + temp.second << "\n";
		}
	}
	return 0;
}