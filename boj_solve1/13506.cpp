#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string str;
int n;
int f[1000005];
int rf[1000005];
int check;
void failure_func(string s, int* arr) {
	int temp = 0;
	for (int i = 1; i < n; i++) {
		while (temp > 0 && s[temp] != s[i]) {
			temp = arr[temp - 1];
		}
		if (s[temp] == s[i]) {
			arr[i] = ++temp;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	n = str.length();
	failure_func(str, f);
	reverse(str.begin(), str.end());
	failure_func(str, rf);
	reverse(rf, rf + n);
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (f[i] > 0 && rf[i - f[i] + 1] == f[i]) {
			ans = max(ans, f[i]);
		}
	}
	if (ans > 0) {
		reverse(str.begin(), str.end());
		for (int i = 0; i < ans; i++) {
			cout << str[i];
		}
	}
	else {
		cout << ans;
	}
	return 0;
}