#include <iostream>
using namespace std;
int check(int n) {
	int temp = 0;
	while (n) {
		int tmp = n % 10;
		n /= 10;
		if (tmp == 6) {
			temp++;
		}
		else {
			temp = 0;
		}
		if (temp == 3) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	int answer = 665;
	while (n) {
		answer++;
		n -= check(answer);
	}
	cout << answer << "\n";
	return 0;
}