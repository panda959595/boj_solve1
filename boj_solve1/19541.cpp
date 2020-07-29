#include <iostream>
#include <vector>
using namespace std;
vector<int> meet[100005];
int n, m;
int arr[100005];
int ans[100005];
int temp[100005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		while (num--) {
			int temp;
			cin >> temp;
			meet[i].push_back(temp);
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
		ans[i + 1] = arr[i + 1];
	}
	for (int i = m - 1; i >= 0; i--) {
		bool flag = false;
		for (auto k : meet[i]) {
			if (ans[k] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			for (auto k : meet[i]) {
				ans[k] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		temp[i] = ans[i];
	}
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (auto k : meet[i]) {
			if (temp[k] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			for (auto k : meet[i]) {
				temp[k] = 1;
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (temp[i] != arr[i]) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}