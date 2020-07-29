#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n;
vector<int> road[300005];
vector< pair<int, int> > line;
long long func_d() {
	long long ret = 0;
	for (auto k : line) {
		long long temp = (road[k.first].size() - 1);
		ret += temp * (road[k.second].size() - 1);
	}
	return ret;
}
long long func_g() {
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		long long temp = road[i].size();
		if (temp < 3) {
			continue;
		}
		ret += temp * (temp - 1) * (temp - 2) / 6;
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		road[a].push_back(b);
		road[b].push_back(a);
		line.push_back({ a,b });
	}
	long long a, b;
	a = func_d();
	b = func_g();
	if (a > b * 3) {
		cout << "D";
	}
	else if (a < b * 3) {
		cout << "G";
	}
	else {
		cout << "DUDUDUNGA";
	}
	return 0;
}