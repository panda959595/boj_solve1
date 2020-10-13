#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int arr[100005];
int n, m, sq;
struct stru {
	int l, r, index;
};
bool comp(stru u, stru v) {
	if (u.l / sq == v.l / sq) {
		return u.r < v.r;
	}
	else {
		return u.l / sq < v.l / sq;
	}
}
stru query[100005];
int cnt[100005];// i 가 몇개인지
int num[100005];// i번 등장한 수의 개수
int ans[100005];
struct st {
	int num;
	int times;
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	sq = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> query[i].l >> query[i].r;
		query[i].index = i;
	}
	sort(query, query + m, comp);
	int l, r;
	l = r = 0;
	int max_num = 0;
	num[0] = n;
	l = query[0].l;
	r = query[0].r;
	for (int i = l; i <= r; i++) {
		int temp = arr[i];
		num[cnt[temp]]--;
		cnt[temp]++;
		num[cnt[temp]]++;
		if (cnt[temp] > max_num) {
			max_num = cnt[temp];
		}
	}
	ans[query[0].index] = max_num;
	for (int i = 1; i < m; i++) {
		while (l < query[i].l) {
			int temp = arr[l];
			num[cnt[temp]]--;
			cnt[temp]--;
			num[cnt[temp]]++;
			while (num[max_num] == 0) {
				max_num--;
			}
			l++;
		}
		while (l > query[i].l) {
			l--;
			int temp = arr[l];
			num[cnt[temp]]--;
			cnt[temp]++;
			num[cnt[temp]]++;
			if (cnt[temp] > max_num) {
				max_num = cnt[temp];
			}
		}
		while (r < query[i].r) {
			r++;
			int temp = arr[r];
			num[cnt[temp]]--;
			cnt[temp]++;
			num[cnt[temp]]++;
			if (cnt[temp] > max_num) {
				max_num = cnt[temp];
			}
		}
		while (r > query[i].r) {
			int temp = arr[r];
			num[cnt[temp]]--;
			cnt[temp]--;
			num[cnt[temp]]++;
			while (num[max_num] == 0) {
				max_num--;
			}
			r--;
		}
		ans[query[i].index] = max_num;
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}