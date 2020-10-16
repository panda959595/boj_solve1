#include <iostream>
using namespace std;
struct point {
	int x, y;
};
point arr[4];
int func(point a, point b, point c) {
	return 1LL * (a.y - b.y) * (a.x - c.x) - 1LL * (a.y - c.y) * (a.x - b.x);
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	long long a = func(arr[0], arr[1], arr[2]);
	long long b = func(arr[0], arr[1], arr[3]);
	if (a * b >= 0) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}