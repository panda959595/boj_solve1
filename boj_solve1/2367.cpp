#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, k, d;
const int S = 0;
const int T = 305;
const int food = 202;
vector<int> road[310];
int c[310][310];
int f[310][310];
int main() {
	cin >> n >> k >> d;
	for (int i = 1; i <= d; i++) {
		int temp;
		cin >> temp;
		road[i + food].push_back(T);
		road[T].push_back(i + food);
		c[i + food][T] = temp;
	}
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		road[S].push_back(i);
		road[i].push_back(S);
		c[S][i] = k;
		for (int j = 0; j < temp; j++) {
			int tmp;
			cin >> tmp;
			road[i].push_back(tmp + food);
			road[tmp + food].push_back(i);
			c[i][tmp + food] = 1;
		}
	}
	int ans = 0;
	while (1) {
		int pre[310];
		memset(pre, -1, sizeof(pre));
		queue<int> que;
		que.push(S);
		pre[S] = S;
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			if (now == T) {
				break;
			}
			for (auto k : road[now]) {
				if (pre[k] != -1 || c[now][k] - f[now][k] <= 0) {
					continue;
				}
				pre[k] = now;
				que.push(k);
			}
		}
		if (pre[T] == -1) {
			break;
		}
		int temp = 987654321;
		for (int now = T; now != S; now = pre[now]) {
			temp = min(temp, c[pre[now]][now] - f[pre[now]][now]);
		}
		for (int now = T; now != S; now = pre[now]) {
			f[pre[now]][now] += temp;
			f[now][pre[now]] -= temp;
		}
		ans += temp;
	}
	cout << ans << endl;
	return 0;
}