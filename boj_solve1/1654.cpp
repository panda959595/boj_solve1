#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10005];
int k, n;
int func(long long l, long long r) {
	if (l == r) {
		return l;
	}
	long long mid = (l + r) / 2 + 1;
	int temp = 0;
	for (int i = 0; i < k; i++) {
		temp += arr[i] / mid;
	}
	if (temp >= n) {
		return func(mid, r);
	}
	else {
		return func(l, mid - 1);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	long long temp = 0;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		temp = max(temp, arr[i]);
	}
	cout << func(1, temp);
	return 0;
}