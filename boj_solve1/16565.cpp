#include <iostream>
using namespace std;
long long c[55][55];
long long func(int n, int r) {
	if (c[n][r] != -1) {
		return c[n][r];
	}
	return c[n][r] = func(n - 1, r - 1) + func(n - 1, r);
}
int main() {
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 55; j++) {
			c[i][j] = -1;
			if (j == 0 || i == j) {
				c[i][j] = 1;
			}
		}
	}
	int n;
	cin >> n;
	long long ans = 0;
	int flag = 1;
	int num = 4;
	while (n>=num) {
		long long temp = 1LL * func(13, num / 4) * func(52 - num, n - num);
		temp %= 10'007;
		ans += temp * flag + 10'007;
		ans %= 10'007;
		flag *= -1;
		num += 4;
	}
	cout << ans << endl;
	return 0;
}