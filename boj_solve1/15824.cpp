#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	long long ans = 0;
	long long temp1, temp2;
	temp1 = 1;
	temp2 = vec[0];
	for (int i = 1; i < n; i++) {
		long long temp = (temp1 * vec[i] - temp2) % 1'000'000'007;
		temp2 *= 2;
		temp2 += vec[i];
		temp1 *= 2;
		temp1++;
		temp1 %= 1'000'000'007;
		temp2 %= 1'000'000'007;
		ans = (ans + temp) % 1'000'000'007;
	}

	cout << ans << endl;
	return 0;
}