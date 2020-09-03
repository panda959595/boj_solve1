#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str;
int f[1000005];
void getf() {
	memset(f, 0, sizeof(f));
	int j = 0;
	for (int i = 1; i < str.length(); i++) {
		while (j > 0 && str[i] != str[j]) {
			j = f[j - 1];
		}
		if (str[i] == str[j]) {
			f[i] = ++j;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> str) {
		if (str == ".") {
			break;
		}
		getf();
		if (str.length() % (str.length() - f[str.length() - 1]) == 0) {
			cout << str.length() / (str.length() - f[str.length() - 1]) << endl;
		}
		else {
			cout << 1 << endl;
		}
	}

	return 0;
}