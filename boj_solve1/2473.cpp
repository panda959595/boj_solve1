#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<long long> vec;
struct stru {
	int a;
	int b;
	stru() {
		a = b = 0;
	}
	stru(int a, int b) {
		this->a = a;
		this->b = b;
	}
};
bool compare(stru u, stru v) {
	return vec[u.a] + vec[u.b] < vec[v.a] + vec[v.b];
}
vector<stru> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());


	long long a, b, c;
	a = b = c = 1'000'000'000;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<long long>::iterator ite = lower_bound(vec.begin(), vec.end(), (vec[i] + vec[j]) * -1);

			int index = ite - vec.begin();

			for (int k = 0; k < 5; k++) {
				if (index + k >= n) {
					break;
				}
				if (index + k == i || index + k == j) {
					continue;
				}
				if (abs(vec[index + k] + vec[i] + vec[j]) < abs(a + b + c)) {
					a = min(vec[index + k], min(vec[i], vec[j]));
					c = max(vec[index + k], max(vec[i], vec[j]));
					b = vec[index + k] + vec[i] + vec[j] - a - c;
				}
			}

			for (int k = 0; k < 5; k++) {
				if (index - k >= n) {
					continue;
				}
				if (index - k < 0) {
					break;
				}
				if (index - k == i || index - k == j) {
					continue;
				}
				if (abs(vec[index - k] + vec[i] + vec[j]) < abs(a + b + c)) {
					a = min(vec[index - k], min(vec[i], vec[j]));
					c = max(vec[index - k], max(vec[i], vec[j]));
					b = vec[index - k] + vec[i] + vec[j] - a - c;
				}
			}

		}
	}
	cout << a << " " << b << " " << c << "\n";
	return 0;
}