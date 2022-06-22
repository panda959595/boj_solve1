#include <iostream>
#include <vector>
using namespace std;
vector<int> prime;
bool check[4'000'005];
int main() {
	for (int i = 2; i < 4'000'005; i++) {
		if (!check[i]) {
			prime.push_back(i);
		}
		for (int j = 1; j * i < 4'000'005; j++) {
			check[j * i] = true;
		}
	}
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < prime.size(); i++) {
		int temp = 0;
		for (int j = i; j < prime.size(); j++) {
			temp += prime[j];
			if (temp == n) {
				ans++;
			}
			if (temp >= n) {
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}