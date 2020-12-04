#include <iostream>
#include <stack>
using namespace std;
long long arr[100005];
int n;
int l[100005];
int r[100005];
long long sum[100005];
int main() {
	cin >> n;
	sum[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	arr[0] = arr[n + 1] = -1;
	stack<pair<int, long long> > sta;// index, value
	sta.push({ 0,-1 });
	for (int i = 1; i <= n; i++) {
		while (sta.top().second >= arr[i]) {
			sta.pop();
		}
		l[i] = sta.top().first;
		sta.push({ i,arr[i] });
	}
	while (!sta.empty()) {
		sta.pop();
	}
	sta.push({ n + 1,-1 });
	for (int i = n; i >= 1; i--) {
		while (sta.top().second >= arr[i]) {
			sta.pop();
		}
		r[i] = sta.top().first;
		sta.push({ i,arr[i] });
	}
	long long ans = -1;
	int s, e;
	s = e = 0;
	for (int i = 1; i <= n; i++) {
		long long temp = (sum[r[i] - 1] - sum[l[i]]) * arr[i];
		if (temp > ans) {
			ans = temp;
			s = l[i] + 1;
			e = r[i] - 1;
		}
		ans = max(ans, temp);
	}
	cout << ans << endl << s << " " << e;
	return 0;
}