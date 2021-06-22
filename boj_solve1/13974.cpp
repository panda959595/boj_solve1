#include <iostream>
using namespace std;
int dp[5005][5005];
int arr[5005];
int sum[5005];
int a[5005][5005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		//n = 5000;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			//arr[i] = 10000;
		}
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + arr[i];
			a[i][i] = i;
		}

		for (int len = 1; len < n; len++) {
			for (int i = 1; i < n; i++) {
				int j = i + len;
				if (j > n) {
					continue;
				}
				dp[i][j] = 1000000000;
				for (int k = a[i][j - 1]; k <= a[i + 1][j]; k++) {
					if (dp[i][j] > dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]) {
						dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
						a[i][j] = k;
					}
				}
			}
		}

		cout << dp[1][n] << "\n";
	}
	return 0;
}