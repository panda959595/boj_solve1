#include <iostream>
#include <cmath>
using namespace std;
int n, m, k, sq;
long long arr[1000005];
long long sq_arr[1005];
long long calc(int s, int e) {
	long long ret = 0;
	while (s % sq != 0 && s <= e) {
		ret += arr[s++];
	}
	while (e % sq != sq - 1 && s <= e) {
		ret += arr[e--];
	}
	while (s <= e) {
		ret += sq_arr[s / sq];
		s += sq;
	}
	return ret;
}
void update(int index, long long num) {
	sq_arr[index / sq] += num - arr[index];
	arr[index] = num;
}
int main() {
	cin >> n >> m >> k;
	sq = sqrt(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sq_arr[i / sq] += arr[i];
	}
	for (int i = 0; i < m + k; i++) {
		long long flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 1) {
			update(a - 1, b);
		}
		else {
			cout << calc(a - 1, b - 1) << endl;
		}
	}
	return 0;
}