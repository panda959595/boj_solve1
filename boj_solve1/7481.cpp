#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b, s;
		bool flag = false;
		cin >> a >> b >> s;
		if (b > a) {
			int temp = a;
			a = b;
			b = temp;
			flag = true;
		}
		int g = gcd(a, b);
		if (s % g != 0) {
			cout << "Impossible\n";
			continue;
		}
		int x, y;
		y = -1;
		x = s / a;
		while (x >= 0) {
			if ((s - a * x) % b == 0) {
				y = (s - a * x)/ b;
			}
			if (y != -1) {
				break;
			}
			x--;
		}
		if (y == -1) {
			cout << "Impossible\n";
			continue;
		}
		if (flag) {
			cout << y << " " << x << "\n";
			continue;
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}