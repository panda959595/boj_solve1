#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<unsigned long long, unsigned long long> func1(unsigned long long n) {
	unsigned long long p, q;
	p = q = 1;
	vector<int> vec;
	while (n > 1) {
		vec.push_back(n % 2);
		n /= 2;
	}
	reverse(vec.begin(), vec.end());
	for (auto flag : vec) {
		if (flag == 0) {
			q += p;
		}
		else {
			p += q;
		}
	}
	return make_pair(p, q);
}
unsigned long long func2(unsigned long long p, unsigned long long q) {
	vector<int> vec;
	while (p != 1 || q != 1) {
		if (p > q) {
			vec.push_back(1);
			p -= q;
		}
		else {
			vec.push_back(0);
			q -= p;
		}
	}
	reverse(vec.begin(), vec.end());
	unsigned long long ret = 1;
	for (auto flag : vec) {
		ret *= 2;
		ret += flag;
	}
	return ret;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int id;
		cin >> id;
		unsigned long long n, p, q;
		if (id == 1) {
			cin >> n;
			pair<unsigned long long, unsigned long long> temp = func1(n);
			p = temp.first;
			q = temp.second;
			cout << "Case #" << t << ": " << p << " " << q << endl;
		}
		else {
			cin >> p >> q;
			n = func2(p, q);
			cout << "Case #" << t << ": " << n << endl;
		}
	}
	return 0;
}