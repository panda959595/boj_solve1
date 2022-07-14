#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> road[1005];
int cnt[1005];
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		int pre = 0;
		while (k--) {
			int temp;
			cin >> temp;
			if (pre != 0) {
				road[pre].push_back(temp);
				cnt[temp]++;
			}
			pre = temp;
		}
	}
	queue<int> que;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			que.push(i);
		}
	}

	while (!que.empty()) {
		int now = que.front();
		que.pop();
		ans.push_back(now);
		for (auto k : road[now]) {
			cnt[k]--;
			if (cnt[k] == 0) {
				que.push(k);
			}
		}
	}
	if (ans.size() != n) {
		cout << 0 << endl;
	}
	else {
		for (auto k : ans) {
			cout << k << endl;
		}
	}
	return 0;
}