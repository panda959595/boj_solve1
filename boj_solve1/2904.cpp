#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[105];
vector<int> prime;
bool check[1000005];
int soinsu[105][78600];
int ans[78600];
int gcd;
int main() {
	for (int i = 2; i < 1000005; i++) {
		if (check[i]) {
			continue;
		}
		prime.push_back(i);
		for (int j = 2; j * i < 1000005; j++) {
			check[i * j] = true;
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < prime.size(); j++) {
			while (arr[i] % prime[j] == 0) {
				arr[i] /= prime[j];
				soinsu[i][j]++;
				ans[j]++;
			}
		}
	}
	gcd = 1;
	int times = 0;
	for (int j = 0; j < prime.size(); j++) {
		ans[j] /= n;
		for (int i = 0; i < ans[j]; i++) {
			gcd *= prime[j];
		}
		for (int i = 0; i < n; i++) {
			if (soinsu[i][j] < ans[j]) {
				times += ans[j] - soinsu[i][j];
			}
		}
	}
	cout << gcd << " " << times;
	return 0;
}