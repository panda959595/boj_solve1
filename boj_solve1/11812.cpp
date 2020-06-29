#include <iostream>
using namespace std;
long long n;
int k, q;
long long h[100];
int get_h(long long num) {
	for (int i = 0; i < 100; i++) {
		if (h[i] >= num) {
			return i - 1;
		}
	}
	return 0;
}
long long max(long long a, long long b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
long long min(long long a, long long b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
long long func(long long a, long long b) {
	if (k == 1) {
		return max(a, b) - min(a, b);
	}
	long long ret = 0;
	int x = get_h(a);
	int y = get_h(b);
	if (x > y) {
		while (x != y) {
			long long temp = a / k;
			temp *= k;
			if (a - temp > 1) {
				a = a / k + 1;
			}
			else {
				a = a / k;
			}
			ret++;
			x--;
		}
	}
	else if (x < y) {
		while (x != y) {
			long long temp = b / k;
			temp *= k;
			if (b - temp > 1) {
				b = b / k + 1;
			}
			else {
				b = b / k;
			}
			ret++;
			y--;
		}
	}
	while (a != b) {
		long long temp = a / k;
		temp *= k;
		if (a - temp > 1) {
			a = a / k + 1;
		}
		else {
			a = a / k;
		}
		temp = b / k;
		temp *= k;
		if (b - temp > 1) {
			b = b / k + 1;
		}
		else {
			b = b / k;
		}
		ret += 2;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> q;
	h[0] = 0;
	long long temp = 1;
	for (int i = 1; i < 100; i++) {
		h[i] = h[i - 1] + temp;
		temp *= k;
	}
	for (int i = 0; i < q; i++) {
		long long a, b;
		cin >> a >> b;
		long long ans = func(a, b);
		cout << ans << "\n";
	}
	return 0;
}