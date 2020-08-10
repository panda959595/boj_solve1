#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<pair<int, int> > road[10005];
int check[10005];
vector<int> pre[10005];
int t[10005];
int s, e;
bool flag[10005];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		check[b]++;
	}
	cin >> s >> e;
	t[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : road[now]) {
			if (--check[k.first] == 0) {
				que.push(k.first);
			}
			if (t[now] + k.second > t[k.first]) {
				pre[k.first].clear();
				t[k.first] = t[now] + k.second;
				pre[k.first].push_back(now);
			}
			else if (t[now] + k.second == t[k.first]) {
				pre[k.first].push_back(now);
			}
		}
	}
	int ans = 0;
	que.push(e);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : pre[now]) {
			ans++;
			if (flag[k]) {
				continue;
			}
			que.push(k);
			flag[k] = true;
		}
	}
	cout << t[e] << "\n" << ans;
	return 0;
}