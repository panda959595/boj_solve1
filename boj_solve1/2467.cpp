#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	int a, b;
	a = b = 1'000'000'000;
	for (auto k : vec) {
		vector<int>::iterator ite = lower_bound(vec.begin(), vec.end(), k * -1);
		for (int i = 0; i < 2; i++) {
			if (ite + i >= vec.end()) {
				break;
			}
			if (k != *(ite + i) && abs(k + *(ite + i)) < abs(a + b)) {
				a = min(k, *(ite + i));
				b = max(k, *(ite + i));
			}
		}
		for (int i = 0; i < 2; i++) {
			if (ite - i == vec.end()) {
				continue;
			}
			if (k != *(ite - i) && abs(k + *(ite - i)) < abs(a + b)) {
				a = min(k, *(ite - i));
				b = max(k, *(ite - i));
			}
			if (ite - i == vec.begin()) {
				break;
			}
		}
	}
	cout << a << " " << b << endl;
	return 0;
}