#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
int parent[4000005];
vector<int> vec;
int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	else {
		return parent[u] = find(parent[u]);
	}
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
		parent[i] = i;
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		vector<int>::iterator ite;
		ite = upper_bound(vec.begin(), vec.end(), temp);
		int num = ite - vec.begin();
		num = find(num);
		cout << vec[num] << "\n";
		merge(num, num + 1);
	}

	return 0;
}