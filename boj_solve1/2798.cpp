#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> card;
	vector<int> p;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		card.push_back(temp);
		p.push_back(0);
	}
	p[n - 1] = p[n - 2] = p[n - 3] = 1;
	int ans = 0;
	do {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			temp += card[i] * p[i];
		}
		if (temp <= m) {
			ans = max(ans, temp);
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << ans << endl;
	return 0;
}