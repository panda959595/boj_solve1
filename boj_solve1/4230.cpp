#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
const int h = 0;
const int w = 35;
const int inverse = 100;
vector<int> road[200];
int stoi_(string str) {
	int ret = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a') {
			break;
		}
		ret *= 10;
		ret += str[i] - '0';
	}
	if (str[str.length() - 1] == 'h') {
		ret += h;
	}
	else {
		ret += w;
	}
	return ret;
}
int scc[200];
int check[200];
int scc_index;
int check_index;
stack<int> sta;
int func(int num) {
	if (check[num] > 0) {
		return 0;
	}
	check[num] = check_index++;
	sta.push(num);
	int temp = check[num];
	for (auto k : road[num]) {
		if (check[k] == -1) {
			temp = min(temp, func(k));
		}
		else if (scc[k] == -1) {
			temp = min(temp, check[k]);
		}
	}
	if (temp == check[num]) {
		while (1) {
			int top = sta.top();
			scc[top] = scc_index;
			sta.pop();
			if (top == num) {
				break;
			}
		}
		scc_index++;
	}
	return temp;
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			road[i + h].clear();
			road[i + w].clear();
			road[i + h + inverse].clear();
			road[i + w + inverse].clear();
			scc[i + h] = scc[i + w] = scc[i + h + inverse] = scc[i + w + inverse] = -1;
			check[i + h] = check[i + w] = check[i + h + inverse] = check[i + w + inverse] = -1;
			road[i + h].push_back(i + w + inverse);
			road[i + h + inverse].push_back(i + w);
			road[i + w].push_back(i + h + inverse);
			road[i + w + inverse].push_back(i + h);
		}
		road[0 + w + inverse].push_back(0 + w);
		scc_index = 1;
		check_index = 1;
		for (int i = 0; i < m; i++) {
			string a, b;
			cin >> a >> b;
			int x, y;
			x = stoi_(a);
			y = stoi_(b);
			//road[x].push_back(y + inverse);
			road[x + inverse].push_back(y);
			//road[y].push_back(x + inverse);
			road[y + inverse].push_back(x);
		}
		for (int i = 0; i < n; i++) {
			func(i + h);
			func(i + w);
			func(i + h + inverse);
			func(i + w + inverse);
		}
		int ans[200] = { 0, };
		vector< pair<int, int> > p;
		bool flag = false;
		for (int i = 0; i < n; i++) {
			p.push_back({ scc[i + h],i + h });
			p.push_back({ scc[i + w], i + w });
			p.push_back({ scc[i + h + inverse], i + h + inverse });
			p.push_back({ scc[i + w + inverse], i + w + inverse });
			if (scc[i + h] == scc[i + h + inverse] || scc[i + w] == scc[i + w + inverse]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "bad luck" << endl;
			continue;
		}
		sort(p.begin(), p.end());
		for (int i = p.size() - 1; i >= 0; i--) {
			if (ans[p[i].second] == 0) {
				if (p[i].second >= 100) {
					ans[p[i].second] = -1;
					ans[p[i].second - inverse] = 1;
				}
				else {
					ans[p[i].second] = -1;
					ans[p[i].second + inverse] = 1;
				}
			}
		}
		for (int i = 1; i < n; i++) {
			if (ans[i] == 1) {
				cout << i << "h ";
			}
			else {
				cout << i << "w ";
			}
		}
		cout << endl;
	}
	return 0;
}