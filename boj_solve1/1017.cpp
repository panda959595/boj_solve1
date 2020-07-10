#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
bool prime[2005];
vector<int> a;
vector<int> b;
vector<int> road[1005];
int partner[1005];
bool check[1005];
int first;
bool func(int num) {
	check[num] = false;
	for (int k : road[num]) {
		if (partner[k] == -1 || check[partner[k]] && func(partner[k])) {
			partner[k] = num;
			return true;
		}
	}
	return false;
}
int main() {
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i < 2005; i++) {
		if (!prime[i]) {
			continue;
		}
		for (int j = 2; i * j < 2005; j++) {
			prime[i * j] = false;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i == 0) {
			first = temp;
			continue;
		}
		if (temp % 2 == first % 2) {
			b.push_back(temp);
		}
		else {
			a.push_back(temp);
		}
	}
	for (int i : a) {
		for (int j : b) {
			if (prime[i + j]) {
				road[i].push_back(j);
			}
		}
	}
	vector<int> vec;
	for (int k : a) {
		if (!prime[k + first]) {
			continue;
		}
		for (int i : b) {
			partner[i] = -1;
		}
		int ans = 0;
		for (int i : a) {
			for (int j : a) {
				check[j] = true;
			}

			if (k == i) {
				continue;
			}
			if (func(i)) {
				ans++;
			}
		}
		if (ans == n / 2 - 1) {
			vec.push_back(k);
		}
	}
	sort(vec.begin(), vec.end());
	if (vec.size() == 0) {
		cout << -1 << endl;
	}
	else {
		for (int k : vec) {
			cout << k << " ";
		}
	}
	return 0;
}