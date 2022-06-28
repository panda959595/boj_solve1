#include <iostream>
#include <vector>
using namespace std;
int a[10];
int b[10];
int c[10];
int idx[10][10];
vector<pair<int, int> > vec;
int board[10][10];
bool flag;
void func(int index) {
	if (index == vec.size()) {
		flag = true;
		return;
	}
	int i = vec[index].first;
	int j = vec[index].second;

	for (int k = 1; k < 10; k++) {
		if ((a[i] & (1 << k)) != 0) {
			continue;
		}
		if ((b[j] & (1 << k)) != 0) {
			continue;
		}
		if ((c[idx[i][j]] & (1 << k)) != 0) {
			continue;
		}
		a[i] |= (1 << k);
		b[j] |= (1 << k);
		c[idx[i][j]] |= (1 << k);
		board[i][j] = k;
		func(index + 1);
		if (flag) {
			return;
		}
		board[i][j] = 0;
		a[i] ^= (1 << k);
		b[j] ^= (1 << k);
		c[idx[i][j]] ^= (1 << k);
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			idx[i][j] = i / 3 * 3 + j / 3;
			char ch;
			cin >> ch;
			int temp = ch - '0';
			board[i][j] = temp;
			if (temp == 0) {
				vec.push_back({ i,j });
			}
			else {
				a[i] |= (1 << temp);
				b[j] |= (1 << temp);
				c[idx[i][j]] |= (1 << temp);
			}
		}
	}
	func(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	return 0;
}