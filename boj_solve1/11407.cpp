#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int S = 0;
const int T = 205;
const int store = 102;
int cost[210][210];
int flow[210][210];
int len[210][210];
vector<int> road[210];
int n, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cost[S][i];
		road[S].push_back(i);
		road[i].push_back(S);
	}
	for (int j = 1; j <= m; j++) {
		cin >> cost[j + store][T];
		road[j + store].push_back(T);
		road[T].push_back(j + store);
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			road[i].push_back(j+store);
			road[j + store].push_back(i);
			cin >> cost[i][j + store];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			road[i].push_back(j + store);
			road[j + store].push_back(i);
			cin >> len[i][j + store];
			len[j + store][i] = -len[i][j + store];
		}
	}
	int ans1 = 0, ans2 = 0;
	while (1) {
		queue<int> que;
		int d[210];
		bool check[210];
		int pre[210];
		for (int i = 0; i < 210; i++) {
			d[i] = 987654321;
			pre[i] = -1;
		}
		memset(check, 0, sizeof(check));
		que.push(S);
		d[S] = 0;
		check[S] = true;
		while (!que.empty()) {
			int now = que.front();
			check[now] = false;
			que.pop();
			for (auto k : road[now]) {
				if (cost[now][k] - flow[now][k] > 0 && d[now] + len[now][k] < d[k]) {
					d[k] = d[now] + len[now][k];
					pre[k] = now;
					if (!check[k]) {
						check[k] = true;
						que.push(k);
					}
				}
			}
		}
		if (pre[T] == -1) {
			break;
		}
		int min_len = 987654321;
		for (int now = T; now != S; now = pre[now]) {
			min_len = min(min_len, cost[pre[now]][now] - flow[pre[now]][now]);
		}
		for (int now = T; now != S; now = pre[now]) {
			flow[pre[now]][now] += min_len;
			flow[now][pre[now]] -= min_len;
			ans2 += min_len * len[pre[now]][now];
		}
		ans1 += min_len;
	}
	cout << ans1 << "\n" << ans2;
	return 0;
}