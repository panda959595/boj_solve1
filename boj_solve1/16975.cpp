#include <iostream>
using namespace std;
long long arr[100005];
long long brr[100005];
int n, m;
void update(int index, int k) {
	for (int i = index; i <= n; i += i & -i) {
		brr[i] += k;
	}
}
long long calc(int index) {
	long long ret = 0;
	for (int i = index; i > 0; i -= i & -i) {
		ret += brr[i];
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i] - arr[i - 1]);
		//brr[i] = arr[i] - arr[i - 1];
	}
	cin >> m;
	while (m--) {
		int flag;
		cin >> flag;
		if (flag == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			update(l, k);
			update(r + 1, -k);
		}
		else {
			int x;
			cin >> x;
			cout << calc(x) << "\n";
		}
	}
	return 0;
}