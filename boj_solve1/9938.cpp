#include <iostream>
using namespace std;
int parent[300005];
int check[300005];
int use[300005];
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
	if (u == v) {
		return;
	}
	parent[v] = u;
	check[u] += check[v];
	use[u] += use[v];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= l; i++) {
		check[i] = 1;
		use[i] = 0;
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
		a = find(a);
		if (use[a] == check[a]) {
			cout << "SMECE\n";
		}
		else {
			cout << "LADICA\n";
			use[a]++;
		}
	}
	return 0;
}