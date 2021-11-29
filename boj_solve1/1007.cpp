#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<double, double> point[25];
int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(6);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> point[i].first >> point[i].second;
		}
		vector<int> per;
		for (int i = 0; i < n / 2; i++) {
			per.push_back(-1);
			per.push_back(1);
		}
		sort(per.begin(), per.end());
		double answer = -1;
		do {
			double x = 0, y = 0;
			for (int i = 0; i < n; i++) {
				x += per[i] * point[i].first;
				y += per[i] * point[i].second;
			}
			if (answer == -1) {
				answer = x * x + y * y;
			}
			answer = min(answer, x * x + y * y);
		} while (next_permutation(per.begin(), per.end()));
		cout << sqrt(answer) << "\n";
	}
	return 0;
}