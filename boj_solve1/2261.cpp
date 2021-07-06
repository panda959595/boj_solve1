#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
struct point {
	int x, y;
	point() {
		x = 0;
		y = 0;
	}
	point(int a, int b) {
		x = a;
		y = b;
	}
	bool operator <(const point& v) const {
		if (y == v.y) {
			return x < v.x;
		}
		else {
			return y < v.y;
		}
	}
};
point arr[100005];
set<point> s;
bool compare(const point& a, const point& b) {
	return a.x < b.x;
}
int distance(point u, point v) {
	return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + n, compare);
	int ans = 0;
	s.insert(arr[0]);
	s.insert(arr[1]);
	ans = distance(arr[0], arr[1]);
	int start = 0;

	for (int i = 2; i < n; i++) {

		while (start < i) {
			if ((arr[i].x - arr[start].x) * (arr[i].x - arr[start].x) > ans) {
				s.erase(arr[start]);
				start++;
			}
			else {
				break;
			}
		}
		int d = (int)sqrt((double)ans) + 1;
		auto lower = s.lower_bound(point(-100000, arr[i].y - d));;
		auto upper = s.upper_bound(point(100000, arr[i].y + d));;
		for (auto k = lower; k != upper; k++) {
			int temp = distance(arr[i], *k);
			if (temp < ans) {
				ans = temp;
			}
		}
		s.insert(arr[i]);
	}
	cout << ans << "\n";
	return 0;
}