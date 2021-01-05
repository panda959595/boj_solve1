#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct stru {
	int index;
	int num;
};
stru arr[1000005];
int n;
int sq;
bool compare1(stru u, stru v) {
	return u.num < v.num;
}
bool compare2(stru u, stru v) {
	return u.index < v.index;
}
struct queryStru {
	int index;
	int s, e;
};
queryStru query[1000005];
int ans[1000005];
bool compare3(queryStru u, queryStru v) {
	if (u.s / sq != v.s / sq) {
		return u.s / sq < v.s / sq;
	}
	else {
		return u.e < v.e;
	}
}
int pre;
int check[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].num;
		arr[i].index = i;
	}
	sort(arr, arr + n, compare1);
	pre = arr[0].num;
	arr[0].num = 0;
	for (int i = 1; i < n; i++) {
		if (pre == arr[i].num) {
			arr[i].num = arr[i - 1].num;
		}
		else {
			pre = arr[i].num;
			arr[i].num = arr[i - 1].num + 1;
		}
	}
	sort(arr, arr + n, compare2);
	sq = sqrt(n);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> query[i].s >> query[i].e;
		query[i].s--;
		query[i].e--;
		query[i].index = i;
	}
	sort(query, query + n, compare3);
	int s, e;
	s = e = -1;
	int temp = 0;
	for (int i = query[0].s; i <= query[0].e; i++) {
		if (++check[arr[i].num] == 1) {
			temp++;
		}
	}
	s = query[0].s;
	e = query[0].e;
	ans[query[0].index] = temp;
	for (int i = 1; i < q; i++) {
		while (s < query[i].s) {
			if (--check[arr[s].num] == 0) {
				temp--;
			}
			s++;
		}
		while (s > query[i].s) {
			s--;
			if (++check[arr[s].num] == 1) {
				temp++;
			}
		}
		while (e < query[i].e) {
			e++;
			if (++check[arr[e].num] == 1) {
				temp++;
			}
		}
		while (e > query[i].e) {
			if (--check[arr[e].num] == 0) {
				temp--;
			}
			e--;
		}
		ans[query[i].index] = temp;
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}