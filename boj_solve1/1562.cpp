#include <iostream>
using namespace std;
long long dp[105][10][1024];
int main() {
	for (int i = 1; i < 10; i++) {
		dp[1][i][1 << i] = 1;
	}

	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j != 0) {
					dp[i + 1][j][(k | (1 << j))] += dp[i][j - 1][k];
				}
				if (j != 9) {
					dp[i + 1][j][(k | (1 << j))] += dp[i][j + 1][k];
				}
				dp[i + 1][j][(k | (1 << j))] %= 1'000'000'000;
			}
		}
	}
	long long ans = 0;
	for (int j = 0; j < 10; j++) {
		ans += dp[n][j][1023];
		ans %= 1'000'000'000;
	}
	
	cout << ans << endl;
	return 0;
}