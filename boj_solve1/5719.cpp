#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int s, e;
int len[505][505];
vector<int> road[505];
vector<int> pre[505];
int cost[505];
bool check[505];
void func() {
	priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;// index, value
	pq.push({ s,0 });
	cost[s] = 0;
	while (!pq.empty()) {
		pair<int, int> now = pq.top();
		pq.pop();
		if (cost[now.first] < now.second) {
			continue;
		}
		for (auto k : road[now.first]) {
			if (len[now.first][k] == -1) {
				continue;
			}
			if (now.second + len[now.first][k] > cost[k]) {
				continue;
			}
			if (now.second + len[now.first][k] < cost[k]) {
				pre[k].clear();
				cost[k] = now.second + len[now.first][k];
				pq.push({ k,cost[k] });
			}
			pre[k].push_back(now.first);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		cin >> s >> e;
		for (int i = 0; i < n; i++) {
			road[i].clear();
			pre[i].clear();
			cost[i] = 987654321;
			check[i] = false;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			road[a].push_back(b);
			len[a][b] = c;
		}
		func();
		queue<int> que;
		que.push(e);
		check[e] = true;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (auto k : pre[now]) {
				len[k][now] = -1;
				if (!check[k]) {
					que.push(k);
					check[k] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cost[i] = 987654321;
		}
		func();
		if (cost[e] == 987654321) {
			cost[e] = -1;
		}
		cout << cost[e] << "\n";
	}
	return 0;
}