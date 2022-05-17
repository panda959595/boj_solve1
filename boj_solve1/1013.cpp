#include <iostream>
#include <string>
using namespace std;
int g[10][2];
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			g[i][j] = -1;
		}
	}
	g[0][0] = 6;
	g[0][1] = 1;
	g[1][0] = 2;
	g[2][0] = 3;
	g[3][0] = 3;
	g[3][1] = 4;
	g[4][0] = 6;
	g[4][1] = 5;
	g[5][1] = 5;
	g[6][1] = 0;
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int now = 0;
		string ans = "YES";
		for (int i = 0; i < str.length(); i++) {
			int flag = str[i] - '0';
			if (now == 5 && flag == 0) {
				if (i + 1 == str.length()) {
					ans = "NO";
					break;
				}
				if (str[i + 1] == '0') {
					now = 2;
				}
				else {
					now = 6;
				}
				continue;
			}
			now = g[now][flag];
			if (now == -1) {
				ans = "NO";
				break;
			}
		}
		if (now != 0 && now != 4 && now != 5) {
			ans = "NO";
		}
		cout << ans << endl;
	}
	return 0;
}