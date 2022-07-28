#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string str;
	while (1) {
		getline(cin, str);
		if (str == ".") {
			break;
		}
		stack<int> sta;
		string flag = "yes";
		for (auto k : str) {
			if (k == '(') {
				sta.push(1);
			}
			else if (k == '[') {
				sta.push(2);
			}
			else if (k == ')') {
				if (sta.empty()) {
					flag = "no";
					break;
				}
				int temp = sta.top();
				sta.pop();
				if (temp != 1) {
					flag = "no";
					break;
				}
			}
			else if (k == ']') {
				if (sta.empty()) {
					flag = "no";
					break;
				}
				int temp = sta.top();
				sta.pop();
				if (temp != 2) {
					flag = "no";
					break;
				}
			}
		}
		if (!sta.empty()) {
			flag = "no";
		}
		cout << flag << endl;
	}
	return 0;
}