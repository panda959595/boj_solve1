#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct point {
	int x, y;
};
bool bigyo1(point a, point b) {
	return a.y < b.y;
}
bool bigyo2(point a, point b) {
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else {
		return a.y > b.y;
	}
}
point arr[75005];
int tree[75005];
int n;
int max_y;
vector<int> temp;
void update(int index) {
	while (index <= max_y) {
		tree[index]++;
		index += (index & -index);
	}
}
int calc(int index) {
	int ret = 0;
	while (index > 0) {
		ret += tree[index];
		index -= (index & -index);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		temp.clear();
		memset(tree, 0, sizeof(tree));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].x >> arr[i].y;
		}
		sort(arr, arr + n, bigyo1);
		int pre = arr[0].y;
		arr[0].y = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i].y > pre) {
				pre = arr[i].y;
				arr[i].y = arr[i - 1].y + 1;
			}
			else {
				arr[i].y = arr[i - 1].y;
			}
		}
		max_y = arr[n - 1].y;
		sort(arr, arr + n, bigyo2);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += calc(max_y) - calc(arr[i].y - 1);
			update(arr[i].y);
		}
		cout << ans << "\n";
	}
	return 0;
}