#include <iostream>
#include <string>
using namespace std;
int arr[1005][1005];
string str;
int n, m;
int x, y;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char mv[4] = { 'R', 'L', 'D', 'U' };
int next[2][4] = {
	{3, 3, 0, 1},
	{3, 3, 1, 0}
};
int p, q;
int flag;
void func3() {
	if (p == n - 1 && q == m - 1) {
		return ;
	}
	while (1) {
		str += mv[flag];
		p += dx[flag];
		q += dy[flag];
		if (p == n - 1 || p == 0) {
			if (p == n - 1 && q == m - 1) {
				break;
			}
			q++;
			str += 'R';
			flag = 5 - flag;
		}
	}
}
void func2(int f) {// 3 : up, 2 : down
	while (1) {
		if (p + dx[flag] == x && q + dy[flag] == y) {
			p += dx[f];
			str += mv[f];
			continue;
		}
		str += mv[flag];
		p += dx[flag];
		q += dy[flag];
		if (flag <= 1) {
			flag = f;
		}
		else if (y==0) {
			if (q == y) {
				flag = 0;
			}
			else {
				flag = 1;
			}
		}
		else {
			if (q == y) {
				flag = 1;
			}
			else {
				flag = 0;
			}
		}
		if (p == n - 1 && q == m - 1) {
			break;
		}
		if (((f == 3 && p == 0) || (f == 2 && p == n - 1)) && ((y == 0 && q == 1) || (y != 0 && q == y))) {
			str += 'R';
			q++;
			flag = 5 - f;
			break;
		}
	}
	func3();
}
void func1() {
	flag = 2;
	while (1) {
		if (q >= y - 1) {
			break;
		}
		str += mv[flag];
		p += dx[flag];
		q += dy[flag];
		if (p == n - 1 || p == 0) {
			str += 'R';
			q++;
			flag = 5-flag;
		}
	}
	flag = 0;
	func2(2 + q % 2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	if (n % 2 == 1) {// 가로먼저
		for (int i = 0; i < n - 1; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < m - 1; j++) {
					str += 'R';
				}
				str += 'D';
			}
			else {
				for (int j = 0; j < m - 1; j++) {
					str += 'L';
				}
				str += 'D';
			}
		}
		for (int j = 0; j < m - 1; j++) {
			str += 'R';
		}
	}
	else if (m % 2 == 1) {
		for (int i = 0; i < m - 1; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < n - 1; j++) {
					str += 'D';
				}
				str += 'R';
			}
			else {
				for (int j = 0; j < n - 1; j++) {
					str += 'U';
				}
				str += 'R';
			}
		}
		for (int j = 0; j < n - 1; j++) {
			str += 'D';
		}
	}
	else {
		int min_happy = 1005;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 1) {
					if (min_happy > arr[i][j]) {
						min_happy = arr[i][j];
						x = i;
						y = j;
					}
				}
			}
		}
		p = q = 0;
		func1();
	}
	cout << str << "\n";

	return 0;
}