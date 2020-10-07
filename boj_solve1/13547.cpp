#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int cnt[1000005];
int arr[100005];
int n, m, sq;
int ans[100005];
struct stru {
	int index, s, e;
};
vector<stru> query;
bool bigyo(stru u, stru v) {
	if (u.s / sq != v.s / sq) {
		return u.s / sq < v.s / sq;
	}
	else {
		return u.e < v.e;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	sq = sqrt(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		query.push_back({ i, a,b });
	}
	sort(query.begin(), query.end(), bigyo);
	int l, r;
	l = r = -1;
	int temp = 0;
	ans[query[0].index] = temp;
	for (auto k : query) {
		if (l == -1) {
			l = k.s;
			r = k.e;
			for (int i = l; i <= r; i++) {
				if (++cnt[arr[i]] == 1) {
					temp++;
				}
			}
			ans[k.index] = temp;
		}
		while (k.s < l) {
			l--;
			if (++cnt[arr[l]] == 1) {
				temp++;
			}
		}
		while (l < k.s) {
			if (--cnt[arr[l]] == 0) {
				temp--;
			}
			l++;
		}
		while (k.e < r) {
			if (--cnt[arr[r]] == 0) {
				temp--;
			}
			r--;
		}
		while (r < k.e) {
			r++;
			if (++cnt[arr[r]] == 1) {
				temp++;
			}
		}
		ans[k.index] = temp;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}