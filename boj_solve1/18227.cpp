#include <iostream>
#include <vector>
using namespace std;
vector<int> road[200005];
vector<int> child[200005];
int level[200005];
void makeTree(int now) {
	for (auto k : road[now]) {
		if (level[k] != 0) {
			continue;
		}
		level[k] = level[now] + 1;
		child[now].push_back(k);
		makeTree(k);
	}
}

int EulerIndex = 0;
int Euler[200005];
pair<int, int> EulerRange[200005];
void dfs(int now) {
	Euler[now] = ++EulerIndex;
	EulerRange[now].first = Euler[now];
	EulerRange[now].second = Euler[now];
	for (auto k : child[now]) {
		dfs(k);
		EulerRange[now].second = EulerIndex;
	}
}

long long st[800005];
void update(int index, int s, int e, int num) {
	if (num < s || e < num) {
		return;
	}
	st[index]++;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update(index * 2, s, mid, num);
	update(index * 2 + 1, mid + 1, e, num);
}
long long calc(int index, int s, int e, int l, int r) {
	if (l <= s && e <= r) {
		return st[index];
	}
	if (r < s || e < l) {
		return 0;
	}
	int mid = (s + e) / 2;
	return calc(index * 2, s, mid, l, r) + calc(index * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	level[c] = 1;
	makeTree(c);
	dfs(c);

	int Q;
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			update(1, 1, n, Euler[b]);
		}
		else {
			cout << calc(1, 1, n, EulerRange[b].first, EulerRange[b].second) * level[b] << "\n";
		}
	}
	return 0;
}