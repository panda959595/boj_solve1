#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
vector<int> vec[10005];
int n, c, m;
int hat[300005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand((unsigned int)time(NULL));
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> hat[i];
		vec[hat[i]].push_back(i);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int flag = -1;
		for (int i = 0; i < 20; i++) {
			int temp = hat[rand() % (b - a + 1) + a];
			vector<int>::iterator ite_lo = lower_bound(vec[temp].begin(), vec[temp].end(), a);
			vector<int>::iterator ite_hi = upper_bound(vec[temp].begin(), vec[temp].end(), b);
			if ((ite_hi - ite_lo) > (b - a + 1) / 2) {
				flag = temp;
				break;
			}
		}
		if (flag != -1) {
			cout << "yes " << flag << "\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}