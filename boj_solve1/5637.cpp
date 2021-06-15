#include <iostream>
#include <string>
using namespace std;
bool check(string str) {
	return str.find("E-N-D");
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	string ans = "";
	while (cin >> str) {
		string temp = "";
		for (auto k : str) {
			if (('a' <= k && k <= 'z') || ('A' <= k && k <= 'Z') || k == '-') {
				temp += k;
			}
			else {
				if (ans.length() < temp.length()) {
					ans = temp;
				}
				/*if (temp.find("E-N-D")) {
					break;
				}*/
			}
		}

		if (temp == "E-N-D") {
			break;
		}

		if (ans.length() < temp.length()) {
			ans = temp;
		}
		
		
		
	}
	for (int i = 0; i < ans.length(); i++) {
		if (ans[i] <= 'Z' && ans[i] != '-') {
			ans[i] += 'a' - 'A';
		}
	}
	cout << ans << "\n";
	return 0;
}