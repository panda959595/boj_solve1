#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stru {
	int up;
	int down;
	bool flag;
	stru(int a, int b, bool c) {
		up = a;
		down = b;
		flag = c;
	}
};
bool compare(stru a, stru b) {
	if (1LL * a.up * b.down != 1LL * a.down * b.up) {
		return 1LL * a.up * b.down < 1LL * a.down * b.up;
	}
	else {
		if (a.flag == b.flag) {
			return false;
		}
		return a.flag;
	}
}
int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
vector<stru> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x, k;
	cin >> n >> x >> k;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int up = num * x;
		int down = 100;
		int g = gcd(max(up, down), min(up, down));
		vec.push_back(stru(up / g, down / g, true));
		up = (200 - x) * num;
		g = gcd(max(up, down), min(up, down));
		vec.push_back(stru(up / g, down / g, false));
	}
	sort(vec.begin(), vec.end(), compare);
	bool flag = true;
	int temp = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].flag) {
			temp++;
		}
		else {
			temp--;
		}
		if (temp >= k) {
			if (vec[i].down == 1) {
				cout << vec[i].up << "\n";
			}
			else {
				cout << vec[i].up << "/" << vec[i].down << "\n";
			}
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "-1\n";
	}
	return 0;
}