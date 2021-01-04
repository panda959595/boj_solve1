#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int n;
vector<int> road[1000005];
vector<int> child[1000005];
bool early[1000005];
int dp[1000005][2];
int func(int now, int flag) {
	if (dp[now][flag] != -1) {
		return dp[now][flag];
	}
	if (flag == 1) {
		int ret = 1;
		for (auto k : child[now]) {
			ret += min(func(k, 1), func(k, 0));
		}
		return dp[now][flag] = ret;
	}
	else {
		int ret = 0;
		for (auto k : child[now]) {
			ret += func(k, 1);
		}
		return dp[now][flag] = ret;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (auto k : road[now]) {
			if (child[k].size() != 0) {
				continue;
			}
			child[now].push_back(k);
			que.push(k);
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i][0] = -1;
	}
	int ans = min(func(1, 1), func(1, 0));
	cout << ans << "\n";
	return 0;
}