#include <iostream>
#include <vector>
using namespace std;
long long st1[400000];
long long st2[400000];
int arr[100005];
long long init_st1(int index, int s, int e) {
	if (s == e) {
		return st1[index] = s;
	}
	int mid = (s + e) / 2;
	return st1[index] = init_st1(index * 2, s, mid) + init_st1(index * 2 + 1, mid + 1, e);
}
long long init_st2(int index, int s, int e) {
	if (s == e) {
		return st2[index] = 1LL * s * s;
	}
	int mid = (s + e) / 2;
	return st2[index] = init_st2(index * 2, s, mid) + init_st2(index * 2 + 1, mid + 1, e);
}
void update_st1(int index, int s, int e, int num, long long value) {
	if (num < s || e < num) {
		return;
	}
	st1[index] += value;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update_st1(index * 2, s, mid, num, value);
	update_st1(index * 2 + 1, mid + 1, e, num, value);
}
void update_st2(int index, int s, int e, int num, long long value) {
	if (num < s || e < num) {
		return;
	}
	st2[index] += value;
	if (s == e) {
		return;
	}
	int mid = (s + e) / 2;
	update_st2(index * 2, s, mid, num, value);
	update_st2(index * 2 + 1, mid + 1, e, num, value);
}
long long calc_st1(int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return st1[index];
	}
	int mid = (s + e) / 2;
	return calc_st1(index * 2, s, mid, l, r) + calc_st1(index * 2 + 1, mid + 1, e, l, r);
}
long long calc_st2(int index, int s, int e, int l, int r) {
	if (r < s || e < l) {
		return 0;
	}
	if (l <= s && e <= r) {
		return st2[index];
	}
	int mid = (s + e) / 2;
	return calc_st2(index * 2, s, mid, l, r) + calc_st2(index * 2 + 1, mid + 1, e, l, r);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		init_st1(1, 1, n);
		init_st2(1, 1, n);
		for (int i = 1; i <= n; i++) {
			arr[i] = i;
		}
		while (k--) {
			int q, a, b;
			cin >> q >> a >> b;
			a++;
			b++;
			if (q == 0) {
				update_st1(1, 1, n, a, arr[b] - arr[a]);
				update_st1(1, 1, n, b, arr[a] - arr[b]);

				update_st2(1, 1, n, a, 1LL * arr[b] * arr[b] - 1LL * arr[a] * arr[a]);
				update_st2(1, 1, n, b, 1LL * arr[a] * arr[a] - 1LL * arr[b] * arr[b]);

				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
			else {
				long long sum = 1LL * b * (b + 1) / 2 - 1LL * (a - 1) * a / 2;
				long long pow_sum = 1LL * b * (b + 1) * (2 * b + 1) / 6 - 1LL * (a - 1) * a * (2 * a - 1) / 6;

				long long temp1 = calc_st1(1, 1, n, a, b);
				long long temp2 = calc_st2(1, 1, n, a, b);
				if (sum == temp1 && pow_sum == temp2) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}