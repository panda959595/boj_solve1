#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[300005];
int num[1000005];
int main() {
	cin >> n;
	cin >> arr[0];
	int mini = arr[0];
	for (int i = 0; i < arr[0]; i++) {
		num[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		for (int j = arr[i]; j < mini; j++) {
			num[j % arr[i]] += num[j];
		}
		mini = min(mini, arr[i]);
	}
	double ans = 0;
	for (int i = 0; i < mini; i++) {
		ans += (double)num[i] * i / arr[0];
	}
	cout << fixed;
	cout.precision(9);
	cout << ans;
	return 0;
}