#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
set<int> dp[105];
int arr[105];
int n;
int sum;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[0].insert(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = n / 2; j >= 0; j--) {
			if (j + n - i < n / 2) {
				continue;
			}
			for (auto k : dp[j]) {
				dp[j + 1].insert(k + arr[i]);
			}
		}
	}
	int ans = 0;
	for (auto k : dp[n / 2]) {
		if (max(k, sum - k) - min(k, sum - k) < max(ans, sum - ans) - min(ans, sum - ans)) {
			ans = k;
		}
	}
	cout << min(ans, sum - ans) << " " << max(ans, sum - ans);
 	return 0;
}