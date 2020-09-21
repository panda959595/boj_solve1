#include <iostream>
using namespace std;
int dp[4][10];
int v, m, t;
long long x, y;
int flag;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
pair<int, int> save[45];
int func(int num) {
	if (num < 10) {
		return num;
	}
	int ret = 0;
	while (num > 0) {
		ret += num % 10;
		num /= 10;
	}
	return func(ret);
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				dp[i][j] = -1;
			}
		}
		cin >> t >> m;
		int index = 0;
		int cycle;
		int start;
		long long mv_x = 0;
		long long mv_y = 0;
		flag = 0;
		x = y = 0;
		v = 1;
		dp[flag][v] = 0;
		bool cnt = false;
		while (1) {
			if (index == t) {
				cout << x << " " << y << endl;
				cnt = true;
				break;
			}
			x += v * dx[flag];
			y += v * dy[flag];
			index++;
			flag++;
			flag %= 4;
			v = func(v * m);
			if (dp[flag][v] != -1) {
				cycle = index - dp[flag][v];
				start = index;
				mv_x = x - save[dp[flag][v]].first;
				mv_y = y - save[dp[flag][v]].second;
				t -= index;
				break;
			}
			dp[flag][v] = index;
			save[dp[flag][v]] = { x,y };
		}
		if (cnt) {
			continue;
		}
		x += mv_x * (t / cycle);
		y += mv_y * (t / cycle);
		for (int i = 0; i < t % cycle; i++) {
			x += v * dx[flag];
			y += v * dy[flag];
			index++;
			flag++;
			flag %= 4;
			v = func(v * m);
		}
		cout << x << " " << y << endl;
	}
	return 0;
}