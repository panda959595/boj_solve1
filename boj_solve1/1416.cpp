#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 999983
vector<int> vec;
int k;
int up_odd, up_even, down_odd, down_even;
long long dp[101][9999];
int s, e;
bool check[10];
long long func(int n, int m) {//n개로 m만들기
	if (m < 0) {
		return 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}
	long long ret = 0;
	for (int i = 0; i < vec.size(); i++) {
		ret += func(n - 1, m - vec[i]);
		ret %= mod;
	}
	return dp[n][m] = ret;
}
long long func1() {
	long long ret = 0;
	for (int i = 0; i <= 450; i++) {// even + odd = i
		long long temp = 0;
		for (int j = 0; j <= i; j++) {// even : j, odd : i-j
			long long ttemp = 1;
			/*if (j < even * s || odd * e < i - j) {
				continue;
			}
			if (j > even* e || odd * s > i - j) {
				break;
			}*/
			ttemp *= func(up_even, j);
			ttemp %= mod;
			ttemp *= func(up_odd, i - j);
			ttemp %= mod;
			temp += ttemp;
			temp %= mod;
		}
		temp *= temp;
		temp %= mod;
		ret += temp;
		ret %= mod;
	}
	return ret;
}
long long func2() {
	long long ret = 0;
	for (int i = 0; i <= 450; i++) {// sum is i
		long long temp1 = 0;
		for (int j = 0; j <= i; j++) {// even : j, even : i-j
			long long temp = 1;
			/*if (j < even * s || even * e < i - j) {
				continue;
			}
			if (j > even* e || even * s > i - j) {
				break;
			}*/
			temp *= func(up_even, j);
			temp %= mod;
			temp *= func(down_even, i - j);
			temp %= mod;
			temp1 += temp;
			temp1 %= mod;
		}

		long long temp2 = 0;
		for (int j = 0; j <= i; j++) {// odd : j, odd : i-j 
			long long temp = 1;
			/*if (j < odd * s || odd * e < i - j) {
				continue;
			}
			if (j > odd* e || odd * s > i - j) {
				break;
			}*/
			temp *= func(up_odd, j);
			temp %= mod;
			temp *= func(down_odd, i - j);
			temp %= mod;
			temp2 += temp;
			temp2 %= mod;
		}
		ret += temp1 * temp2;
		ret %= mod;
	}
	return ret;
}
long long func3() {
	long long ret = 0;
	for (int i = 0; i <= 450; i++) {// sum is i
		bool flag = true;
		for (int j = 0; j <= i; j++) {
			long long temp = 1;
			/*if (j < even * s || j < odd * s || even * e < i - j || odd * e < i - j) {
				continue;
			}
			if (j > even* e || j > odd* e || even * s > i - j || odd * s > i - j) {
				break;
			}*/
			temp *= func(up_even, j);
			temp %= mod;
			temp *= func(down_even, i - j);
			temp %= mod;
			temp *= func(down_odd, j);
			temp %= mod;
			temp *= func(up_odd, i - j);
			temp %= mod;
			ret += temp;
			ret %= mod;
		}
	}
	return ret;
}
int main() {
	cin >> k;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (check[str[i] - '0']) {
			continue;
		}
		vec.push_back(str[i] - '0');
		dp[1][str[i] - '0'] = 1;
		check[str[i] - '0'] = true;
	}
	sort(vec.begin(), vec.end());
	s = *(vec.begin());
	e = *(vec.end() - 1);
	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 9999; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		dp[1][vec[i]] = 1;
	}
	down_even = k / 2;
	down_odd = (k - 1) / 2 + 1;

	up_even = down_odd;
	up_odd = down_even;

	if (k == 1) {
		cout << vec.size() << endl;
		return 0;
	}
	long long f1 = func1();
	long long f2 = func2();
	long long f3 = func3();
	long long ans = func1() + func2() - func3();
	ans %= mod;
	ans += mod * 2;
	ans %= mod;
	cout << ans << endl;
	return 0;
}