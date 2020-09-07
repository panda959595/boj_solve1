#include <iostream>
#include <algorithm>
using namespace std;
int arr[2][10005];
int n, w;
int ans;
int dp[3][10005];
void func(int flag) {
	dp[0][0] = dp[1][0] = dp[2][0] = 0;
	dp[0][1] = 1;
	dp[1][1] = 1;
	if (arr[0][1] + arr[1][1] <= w) {
		dp[2][1] = 1;
	}
	else {
		dp[2][1] = 2;
	}
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[2][i - 1] + 1;
		dp[1][i] = dp[2][i - 1] + 1;
		dp[2][i] = dp[2][i - 1] + 2;
		if (arr[0][i] + arr[0][i - 1] <= w) {
			dp[0][i] = min(dp[0][i], dp[1][i - 1] + 1);
		}
		if (arr[1][i] + arr[1][i - 1] <= w) {
			dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
		}
		if (arr[0][i] + arr[0][i - 1] <= w) {
			dp[2][i] = min(dp[2][i], dp[1][i - 1] + 2);
		}
		if (arr[1][i] + arr[1][i - 1] <= w) {
			dp[2][i] = min(dp[2][i], dp[0][i - 1] + 2);
		}
		if (arr[0][i] + arr[0][i - 1] <= w && arr[1][i] + arr[1][i - 1] <= w) {
			dp[2][i] = min(dp[2][i], dp[2][i - 2] + 2);
		}
		if (arr[0][i] + arr[1][i] <= w) {
			dp[2][i] = min(dp[2][i], dp[2][i - 1] + 1);
		}
	}
	ans = min(ans, dp[2][n] - flag);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> w;
		ans = 1000000;
		for (int i = 1; i <= n; i++) {
			cin >> arr[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> arr[1][i];
		}
		func(0);
		if (n > 1 && arr[0][1] + arr[0][n] <= w) {
			int temp1 = arr[0][1];
			int temp2 = arr[0][n];
			arr[0][1] = arr[0][n] = w + 5;
			func(1);
			arr[0][1] = temp1;
			arr[0][n] = temp2;
		}
		if (n > 1 && arr[1][1] + arr[1][n] <= w) {
			int temp1 = arr[1][1];
			int temp2 = arr[1][n];
			arr[1][1] = arr[1][n] = w + 5;
			func(1);
			arr[1][1] = temp1;
			arr[1][n] = temp2;
		}
		if (n > 1 && arr[0][1] + arr[0][n] <= w && arr[1][1] + arr[1][n] <= w) {
			arr[0][1] = arr[0][n] = arr[1][1] = arr[1][n] = w + 5;
			func(2);
		}
		cout << ans << "\n";
	}
	return 0;
}