#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double c[100005];
double w[100005];
struct point {
	double c;
	double w;
};
point arr[100005];
bool compare(point a, point b) {
	return a.c < b.c;
}
int main() {
	int n;
	double A;
	cin >> n >> A;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[i].c = sqrt(pow(x, 2) + pow(y, 2));
		arr[i].w = z;
	}
	sort(arr, arr + n, compare);
	double ans = 0;
	A *= -1;
	double B = 0;
	double C = 0;
	for (int i = 0; i < n; i++) {
		B += arr[i].w;
		C -= arr[i].w * arr[i].c;
		double x = B / (2 * A) * -1;
		double temp = A * pow(x, 2) + B * x + C;
		if (ans < temp) {
			ans = temp;
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << ans << endl;
	return 0;
}