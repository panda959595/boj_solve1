#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long sum = 0;
	long long exclusive = 0;
	while (n--) {
		int flag;
		int temp;
		cin >> flag;
		if (flag == 1) {
			cin >> temp;
			sum += temp;
			exclusive ^= temp;
		}
		else if (flag == 2) {
			cin >> temp;
			sum -= temp;
			exclusive ^= temp;
		}
		else if (flag == 3) {
			cout << sum << "\n";
		}
		else {
			cout << exclusive << "\n";
		}
	}
	return 0;
}