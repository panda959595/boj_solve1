#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0) {
			break;
		}
		int m = max(a, max(b, c));
		int temp = a * a + b * b + c * c;
		if (m * m * 2 == temp) {
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
	}

	return 0;
}