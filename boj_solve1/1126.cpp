#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define veryMin -987654321;
int arr[51];
int dp[51][500001];
int n;
int func(int num, int diff) {
	if (dp[num][diff] != -1) {
		return dp[num][diff];
	}
	if (num == n) {
		if (diff == 0) {
			return 0;
		}
		else {
			return veryMin;
		}
	}
	int ret = veryMin;
	ret = max(ret, func(num + 1, diff));
	ret = max(ret, func(num + 1, diff + arr[num]));
	if (arr[num] > diff) {
		ret = max(ret, func(num + 1, arr[num] - diff) + diff);
	}
	else {
		ret = max(ret, func(num + 1, diff - arr[num]) + arr[num]);
	}
	return dp[num][diff] = ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof(dp));
	int ans = func(0, 0);
	if (ans <= 0) {
		ans = -1;
	}
	cout << ans;
	return 0;
}