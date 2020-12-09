#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> vec1;
struct stru {
	int i, j;
	int num;
	bool operator<(stru temp) {
		return num < temp.num;
	}
	bool operator>(stru temp) {
		return num > temp.num;
	}
};
vector<stru> vec2;
bool bigyo(stru a, stru b) {
	return a.num < b.num;
}
int func() {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			stru temp;
			temp.i = temp.j = 0;
			temp.num = vec1[i] - vec1[j];
			vector<stru>::iterator ite = lower_bound(vec2.begin(), vec2.end(), temp, bigyo);
			if (ite == vec2.end() || ite->num != temp.num) {
				continue;
			}
			do {
				if (i != ite->i && i != ite->j && j != ite->i && j != ite->j) {
					return vec1[i];
				}
				ite++;
				if (ite == vec2.end()) {
					break;
				}
			} while (ite->num == (ite - 1)->num);
		}
	}
	return -536870913;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vec1.clear();
		vec2.clear();
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			vec1.push_back(temp);
		}
		sort(vec1.begin(), vec1.end());
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				stru temp;
				temp.i = i;
				temp.j = j;
				temp.num = vec1[i] + vec1[j];
				vec2.push_back(temp);
			}
		}
		sort(vec2.begin(), vec2.end() , bigyo);
		int ans = func();
		if (ans == -536870913) {
			cout << "no solution\n";
		}
		else {
			cout << ans << "\n";
		}

	}
	return 0;
}