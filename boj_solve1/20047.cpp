#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
string str1;
string str2;
int n, a, b;
char arr[2];
int dp[3][10005];
int func(int use, int index) {
	if (dp[use][index] != 0) {
		return dp[use][index];
	}
	int ret = -1;
	if (index == str1.length()) {
		if (use == 0) {
			if (arr[use] == str2[use + index]) {
				return dp[use][index] = func(use + 1, index);
			}
			return dp[use][index] = -1;
		}
		else if (use == 1) {
			if (arr[use] == str2[use + index]) {
				return dp[use][index] = 1;
			}
			return dp[use][index] = -1;
		}
		else {
			return dp[use][index] = 1;
		}
	}
	if (str1[index] == str2[use + index]) {
		ret = func(use, index + 1);
	}
	if (use < 2) {
		int temp = -1;
		if (arr[use] == str2[use + index]) {
			temp = func(use + 1, index);
		}
		if (temp == 1) {
			ret = 1;
		}
	}
	return dp[use][index] = ret;
}
int main() {
	cin >> n;
	cin >> str;
	cin >> str2;
	cin >> a >> b;
	str1 = "";
	arr[0] = str[a];
	arr[1] = str[b];
	for (int i = 0; i < n; i++) {
		if (i == a || i == b) {
			continue;
		}
		str1 += str[i];
	}
	if (func(0, 0) == 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}