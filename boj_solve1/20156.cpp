#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
int parent[100005];
int mentor[100005];
int check[100005];
struct stru {
	int flag;
	int time;
	int a;
	int b, c;
	int ansIndex;
};
vector<stru> query;
vector< pair<int,int> > ans;
bool compare(stru u, stru v) {
	if (u.time != v.time) {
		return u.time < v.time;
	}
	else {
		return u.flag < v.flag;
	}
}
int find(int u) {
	if (parent[u] == u) {
		return u;
	}
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		parent[u] = v;
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> mentor[i];
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		stru temp;
		cin >> temp.a;
		if (check[temp.a]) {
			continue;
		}
		temp.time = i + 1;
		temp.flag = 0;
		query.push_back(temp);
		check[temp.a] = true;
	}
	for (int i = 0; i < k; i++) {
		stru temp;
		cin >> temp.time >> temp.b >> temp.c;
		temp.flag = 1;
		temp.ansIndex = i;
		query.push_back(temp);
	}
	sort(query.begin(), query.end(), compare);
	for (int i = 1; i <= n; i++) {
		if (check[i] || mentor[i] == -1) {
			continue;
		}
		merge(i, mentor[i]);
	}
	reverse(query.begin(), query.end());
	for (auto k : query) {
		if (k.flag == 0) {
			if (mentor[k.a] != -1) {
				merge(k.a, mentor[k.a]);
			}
		}
		else {
			int u = find(k.b);
			int v = find(k.c);
			if (u == v) {
				ans.push_back({ k.ansIndex, 1 });
			}
			else {
				ans.push_back({ k.ansIndex, 0 });
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (auto k : ans) {
		if (k.second == 1) {
			cout << "Same Same;\n";
		}
		else {
			cout << "No;\n";
		}
	}
	return 0;
}