#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int charge[100005];
bool zombie[100005];
bool check[100005];
long long cost[100005];
vector<int> road[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, l;
	int p, q;
	cin >> n >> m >> k >> l;
	cin >> p >> q;
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		charge[i] = p;
		cost[i] = 9876543210123;
	}
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		zombie[temp] = true;
		que.push(temp);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	while (l--) {
		int size = que.size();
		while (size--) {
			int now = que.front();
			que.pop();
			for (auto k : road[now]) {
				if (zombie[k] || charge[k] == q) {
					continue;
				}
				charge[k] = q;
				que.push(k);
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	cost[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (check[now.second]) {
			continue;
		}
		check[now.second] = true;
		for (auto k : road[now.second]) {
			if (check[k] || zombie[k]) {
				continue;
			}
			if (cost[k] > cost[now.second] + charge[now.second]) {
				cost[k] = cost[now.second] + charge[now.second];
				pq.push({ cost[k], k });
			}
		}
	}
	cout << cost[n] - charge[1] << endl;
	return 0;
}