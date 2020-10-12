#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct stru {
	int s, e, index;
};
int arr[100005];
stru query[100005];
int n, m, sq;
long long ans[100005];
long long ans_temp;
int cnt[1000005];
bool comp(stru u, stru v) {
	if (u.s / sq != v.s / sq) {
		return u.s / sq < v.s / sq;
	}
	return u.e < v.e;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> query[i].s >> query[i].e;
		query[i].index = i;
	}
	sort(query, query + m, comp);
	for (int i = query[0].s; i <= query[0].e; i++) {
		ans_temp -= 1LL * cnt[arr[i]] * cnt[arr[i]] * arr[i];
		cnt[arr[i]]++;
		ans_temp += 1LL * cnt[arr[i]] * cnt[arr[i]] * arr[i];
	}
	ans[query[0].index] = ans_temp;
	int l = query[0].s;
	int r = query[0].e;
	for (int i = 1; i < m; i++) {
		while (l < query[i].s) {
			ans_temp -= 1LL * cnt[arr[l]] * cnt[arr[l]] * arr[l];
			cnt[arr[l]]--;
			ans_temp += 1LL * cnt[arr[l]] * cnt[arr[l]] * arr[l];
			l++;
		}
		while (l > query[i].s) {
			l--;
			ans_temp -= 1LL * cnt[arr[l]] * cnt[arr[l]] * arr[l];
			cnt[arr[l]]++;
			ans_temp += 1LL * cnt[arr[l]] * cnt[arr[l]] * arr[l];
		}
		while (r < query[i].e) {
			r++;
			ans_temp -= 1LL * cnt[arr[r]] * cnt[arr[r]] * arr[r];
			cnt[arr[r]]++;
			ans_temp += 1LL * cnt[arr[r]] * cnt[arr[r]] * arr[r];
		}
		while (r > query[i].e) {
			ans_temp -= 1LL * cnt[arr[r]] * cnt[arr[r]] * arr[r];
			cnt[arr[r]]--;
			ans_temp += 1LL * cnt[arr[r]] * cnt[arr[r]] * arr[r];
			r--;
		}
		ans[query[i].index] = ans_temp;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}