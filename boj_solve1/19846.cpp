#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, m, q;
string str = "";
int main() {
	cin >> n >> m >> q;
	int flag = 0;
	for (int i = 0; i < m; i++) {
		str += 'a' + flag / 2;
		flag++;
		if (flag / 2 == n) {
			flag = 0;
		}
	}
	cout << str << endl;
	return 0;
}