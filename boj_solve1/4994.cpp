#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	int n;
	while (1) {
		cin >> n;
		string ans;
		if (n == 0) {
			break;
		}
		queue<pair<string, int> > que;
		que.push({ "1",1 });
		while (!que.empty()) {
			pair<string, int> now = que.front();
			que.pop();
			if (now.second == 0) {
				ans = now.first;
				break;
			}
			for (int i = 0; i < 2; i++) {
				pair<string, int> temp;
				string tmp = "0";
				tmp[0] += i;
				temp.first = now.first + tmp;
				temp.second = (10 * now.second + i) % n;
				que.push(temp);
			}
		}
		cout << ans << endl;
	}

	return 0;
}