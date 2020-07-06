#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool even[105];
int odd[105];
vector<int> road[105];
char arr[12][12];
int dx[6] = { -1,-1,0 ,0,1,1 };
int dy[6] = { -1,1,-1 ,1,-1,1 };
bool func(int num) {
	if (!even[num]) {
		return false;
	}
	even[num] = false;
	for (auto k : road[num]) {
		if (odd[k] == -1 || even[odd[k]] && func(odd[k])) {
			odd[k] = num;
			return true;
		}
	}
	return false;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '.') {
					ans++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j += 2) {
				if (arr[i][j] == 'x') {
					continue;
				}
				road[i * m + j].clear();
				for (int k = 0; k < 6; k++) {
					if (i + dx[k] < 0 || i + dx[k] > n - 1 || j + dy[k] < 0 || j + dy[k] > m - 1 || arr[i + dx[k]][j + dy[k]] == 'x') {
						continue;
					}
					road[i * m + j].push_back((i + dx[k]) * m + j + dy[k]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j += 2) {
				odd[i * m + j] = -1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j += 2) {
				if (arr[i][j] == 'x') {
					continue;
				}
				for (int a = 0; a < n; a++) {
					for (int b = 0; b < m; b += 2) {
						even[a * m + b] = true;
					}
				}
				if (func(i * m + j)) {
					ans--;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}