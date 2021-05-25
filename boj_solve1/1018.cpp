#include <iostream>
using namespace std;
char board[55][55];
int calc(int x, int y) {
	char flag = board[x][y];
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && board[i + x][j + y] != flag) {
				ret++;
			}
			else if ((i + j) % 2 == 1 && board[i + x][j + y] == flag) {
				ret++;
			}
		}
	}
	return min(ret, 64 - ret);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int ans = 1000;
	for (int i = 0; i < n - 8 + 1; i++) {
		for (int j = 0; j < m - 8 + 1; j++) {
			ans = min(ans, calc(i, j));
		}
	}
	cout << ans << endl;
	return 0;
}