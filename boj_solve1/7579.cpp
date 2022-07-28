#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int memory[105], cost[105];
int dp[10'005][2];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	int flag = 0;
	int r[2] = { 1, 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10'005; j++) {
			dp[j][r[flag]] = max(dp[j][0], dp[j][1]);
			if (j == 0 || dp[j][flag] != 0) {
				dp[j + cost[i]][r[flag]] = max(dp[j + cost[i]][r[flag]], dp[j][flag] + memory[i]);
			}
		}
		flag = r[flag];
	}
	int ans = 100000;
	for (int i = 0; i < 10'005; i++) {
		if (dp[i][flag] >= m) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}