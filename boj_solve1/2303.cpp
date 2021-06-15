#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10][10][10][10][10];
int arr[1005][10];
int func(int* num) {
	if (dp[num[0] % 10][num[1] % 10][num[2] % 10][num[3] % 10][num[4] % 10] != -1) {
		return dp[num[0] % 10][num[1] % 10][num[2] % 10][num[3] % 10][num[4] % 10];
	}
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	int ret = 0;
	do {
		int temp = 0;
		for (int i = 0; i < 5; i++) {
			temp += vec[i] * num[i];
		}
		temp %= 10;
		ret = max(ret, temp);
	} while (next_permutation(vec.begin(), vec.end()));
	return dp[num[0] % 10][num[1] % 10][num[2] % 10][num[3] % 10][num[4] % 10] = ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = 1;
	int num = -1;
	for (int i = 1; i <= n; i++) {
		int temp = func(arr[i]);
		if (temp >= num) {
			num = temp;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}