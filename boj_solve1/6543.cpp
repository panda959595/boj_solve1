#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> road[5005];
int scc[5005];
int sccIndex;
int checkIndex;
int check[5005];
stack<int> sta;
int dfs(int now) {
	check[now] = checkIndex++;
	int ret = check[now];
	sta.push(now);
	for (auto k : road[now]){
		if (check[k] == -1) {
			ret = min(ret, dfs(k));
		}
		else if (scc[k] == -1) {
			ret = min(ret, check[k]);
		}
	}
	if (check[now] == ret) {
		while (!sta.empty()) {
			int top = sta.top();
			sta.pop();
			scc[top] = sccIndex;
			if (top == now) {
				break;
			}
		}
		sccIndex++;
	}
	return ret;
}

bool sccCheck[5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cin >> m;
		sccIndex = 1;
		checkIndex = 1;
		for (int i = 1; i <= n; i++) {
			road[i].clear();
			scc[i] = -1;
			check[i] = -1;
			sccCheck[i] = true;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			road[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == -1) {
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (auto k : road[i]) {
				if (scc[i] != scc[k]) {
					sccCheck[scc[i]] = false;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (sccCheck[scc[i]]) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}