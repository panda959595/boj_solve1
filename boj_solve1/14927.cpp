#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[20][20];
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int bright;
int ans;
int temp;
void calc() {
	int brr[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			brr[i][j] = arr[i][j];
		}
	}
	int tmp = 0;
	int btemp = bright;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (brr[i - 1][j]) {
				tmp++;
				for (int k = 0; k < 5; k++) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x < 0 || x >= n || y < 0 || y >= n) {
						continue;
					}
					if (brr[x][y]) {
						bright--;
					}
					else {
						bright++;
					}
					brr[x][y] ^= 1;
				}
			}
		}
	}
	if (bright == 0) {
		ans = min(ans, temp + tmp);
	}
	bright = btemp;
}
void func(int num) {
	if (num == n) {
		calc();
		return;
	}
	func(num + 1);
	for (int i = 0; i < 5; i++) {
		int x = dx[i];
		int y = num + dy[i];
		if (x < 0 || x >= n || y < 0 || y >= n) {
			continue;
		}
		if (arr[x][y]) {
			bright--;
		}
		else {
			bright++;
		}
		arr[x][y] ^= 1;
	}
	temp++;
	func(num + 1);
	temp--;
	for (int i = 0; i < 5; i++) {
		int x = dx[i];
		int y = num + dy[i];
		if (x < 0 || x >= n || y < 0 || y >= n) {
			continue;
		}
		if (arr[x][y]) {
			bright--;
		}
		else {
			bright++;
		}
		arr[x][y] ^= 1;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				bright++;
			}
		}
	}
	ans = n * n + 5;
	func(0);
	if (ans == n * n + 5) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}