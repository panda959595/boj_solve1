#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > change[11][11];
int dx[5] = { 0, 0,0,1,-1 };
int dy[5] = { 0, 1,-1,0,0 };
int ans;
int temp;
int bright;
string bulb[11];
void func() {
	int tmp = 0;
	vector<pair<int, int> > vec;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (bulb[i - 1][j] == 'O') {
				vec.push_back({ i,j });
				for (auto k : change[i][j]) {
					if (bulb[k.first][k.second] == '#') {
						bulb[k.first][k.second] = 'O';
						bright++;
					}
					else {
						bulb[k.first][k.second] = '#';
						bright--;
					}
				}
				tmp++;
			}
		}
	}
	if (bright == 0) {
		ans = min(ans, temp + tmp);
	}
	for (auto l : vec) {
		int i = l.first;
		int j = l.second;
		for (auto k : change[i][j]) {
			if (bulb[k.first][k.second] == '#') {
				bulb[k.first][k.second] = 'O';
				bright++;
			}
			else {
				bulb[k.first][k.second] = '#';
				bright--;
			}
		}
	}
}
void first_line(int j) {
	if (j == 10) {
		func();
		return;
	}
	first_line(j + 1);
	for (auto k : change[0][j]) {
		if (bulb[k.first][k.second] == '#') {
			bulb[k.first][k.second] = 'O';
			bright++;
		}
		else {
			bulb[k.first][k.second] = '#';
			bright--;
		}
	}
	temp++;
	first_line(j + 1);
	for (auto k : change[0][j]) {
		if (bulb[k.first][k.second] == '#') {
			bulb[k.first][k.second] = 'O';
			bright++;
		}
		else {
			bulb[k.first][k.second] = '#';
			bright--;
		}
	}
	temp--;
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 5; k++) {
				pair<int, int> temp;
				temp = make_pair(i + dx[k], j + dy[k]);
				if (temp.first < 0 || temp.first >9 || temp.second < 0 || temp.second > 9) {
					continue;
				}
				change[i][j].push_back(temp);
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cin >> bulb[i];
		for (int j = 0; j < 10; j++) {
			if (bulb[i][j] == 'O') {
				bright++;
			}
		}
	}
	ans = 1000;
	first_line(0);
	if (ans == 1000) {
		ans = -1;
	}
	cout << ans << "\n";
	return 0;
}