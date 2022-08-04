#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int n;
map<string, int> road[15'005];
string name[15'005];
int depth[15'005];
void func(int now) {
	if (now != 1) {
		for (int i = 0; i < depth[now]; i++) {
			cout << "--";
		}
		cout << name[now] << endl;
	}
	for (auto k : road[now]) {
		func(k.second);
	}
}
int main() {
	cin >> n;
	int index = 2;
	depth[1] = -1;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int pre = -1;
		int now = 1;
		for (int j = 0; j < k; j++) {
			string temp;
			cin >> temp;
			if (road[now][temp] == 0) {
				road[now][temp] = index;
				depth[index] = depth[now] + 1;
				name[index] = temp;
				index++;
			}
			now = road[now][temp];
		}
	}
	func(1);
	return 0;
}