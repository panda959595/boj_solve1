#include <iostream>
#include <string>
#include <list>
using namespace std;
string str1, str2;
int dp[105][105];
pair<int, int> pre[105][105];
int func(int i, int j) {
	if (i == -1 || j == -1) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (str1[i] == str2[j]) {
		pre[i][j] = make_pair(i - 1, j - 1);
		return dp[i][j] = func(i - 1, j - 1) + 1;
	}
	int ret = 0;
	for (int x = 0; x <= i; x++) {
		for (int y = 0; y <= j; y++) {
			if (x == i && y == j) {
				continue;
			}
			if (str1[x] == str2[y]) {
				int temp = func(x, y);
				if (temp > ret) {
					ret = temp;
					pre[i][j] = make_pair(x, y);
				}
			}
		}
	}
	return dp[i][j] = ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> str1 >> str2) {
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) {
				dp[i][j] = -1;
			}
		}
		for (int i = str1.length() - 1; i >= 0; i--) {
			for (int j = str2.length() - 1; j >= 0; j--) {
				func(i, j);
			}
		}
		list<char> com;
		int x = str1.length() - 1;
		int y = str2.length() - 1;
		while (1) {
			if (dp[x][y] == 0) {
				break;
			}
			if (str1[x] == str2[y]) {
				com.push_front(str1[x]);
				if (dp[x][y] == 1) {
					break;
				}
			}
			pair<int, int> temp = pre[x][y];
			x = temp.first;
			y = temp.second;
		}
		list<char> ans;
		for (int i = 0; i < str1.length(); i++) {
			ans.push_back(str1[i]);
		}
		list<char>::iterator input = ans.begin();
		list<char>::iterator ite = com.begin();
		for (int i = 0; i < str2.length(); i++) {
			if (ite != com.end() && str2[i] == *ite) {
				while (*input != *ite) {
					input++;
				}
				input++;
				ite++;
			}
			else {
				ans.insert(input, str2[i]);
			}
		}
		for (list<char>::iterator i = ans.begin(); i != ans.end(); i++) {
			cout << *i;
		}
		cout << "\n";
	}
	return 0;
}