#include <iostream>
#include <algorithm>
using namespace std;
int n, m, b;
int arr[300];
int main() {
	cin >> n >> m >> b;
	int T, t;
	t = 300;
	T = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			arr[temp]++;
			t = min(t, temp);
			T = max(T, temp);
			
		}
	}
	int ans = 1'000'000'000;
	int h;
	int down, up, downTemp, upTemp;
	down = up = downTemp  = upTemp = 0;
	for (int i = T; i >= t; i--) {
		up += (T - i)* arr[i];
		upTemp += arr[i];
	}
	
	for (int i = T; i >= t; i--) {
		int temp = 0;
		int tmp = b;
		temp += 2 * down;
		tmp += down;

		if (tmp >= up) {
			temp += up;
			if (ans > temp) {
				ans = temp;
				h = i;
			}
		}
		downTemp += arr[i];
		down += downTemp;
		upTemp -= arr[i];
		up -= upTemp;
	}
	cout << ans << " " << h << endl;
	return 0;
}