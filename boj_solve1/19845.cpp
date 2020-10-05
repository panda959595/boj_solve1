#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, q;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		y = n - y;
		int ans = 0;
		ans += max(0, vec[y] - x);
		vector<int>::iterator ite = lower_bound(vec.begin(), vec.end(), x);
		ans += max(0, y - (int)(ite - vec.begin()));
		if (vec[y] >= x) {
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}