#include <iostream>
#include <map>
using namespace std;
int T, n;
int main() {
	map<string, int> ma;
	ma["Mon"] = 0;
	ma["Tue"] = 1;
	ma["Wed"] = 2;
	ma["Thu"] = 3;
	ma["Fri"] = 4;
	cin >> T >> n;
	for (int i = 0; i < n; i++) {
		string day1, day2;
		int s, e;
		cin >> day1 >> s >> day2 >> e;
		T -= e + ma[day2] * 24 - (s + ma[day1] * 24);
	}
	if (T < 0) {
		T = 0;
	}
	if (T > 48) {
		T = -1;
	}
	cout << T << endl;
	return 0;
}