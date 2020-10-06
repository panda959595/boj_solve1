#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
int dp[251][62505];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 62505; j++) {
			dp[i][j] = 100000000;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < 62505; j++) {
			if (dp[i][j] == 100000000) {
				continue;
			}
			dp[i + 1][j + a] = min(dp[i + 1][j + a], dp[i][j]);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
		}
	}
	int ans = 100000000;
	for (int i = 0; i < 62505; i++) {
		if (dp[n][i] == 100000000) {
			continue;
		}
		ans = min(ans, max(i, dp[n][i]));
	}
	cout << ans << endl;
	return 0;
}