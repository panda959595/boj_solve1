#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	cout << fixed;
	cout.precision(6);
	while (T--) {
		double h, m, s;
		cin >> h >> m >> s;
		vector<double> vec;
		vec.push_back(h / 12 * 360 + m / 60 * 30 + s / 3600 * 30);
		vec.push_back(m / 60 * 360 + s / 60 * 6);
		vec.push_back(s / 60 * 360);
		sort(vec.begin(), vec.end());
		double ans = 0;
		ans = min(min(vec[1] - vec[0], vec[2] - vec[1]), vec[0] + 360 - vec[2]);
		if (ans >= 360) {
			ans -= 360;
		}
		cout << ans << endl;
	}
	return 0;
}