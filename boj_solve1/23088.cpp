#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int nowTime;
struct process {
	int number;
	int start;
	int order;
	int t;
	process(int a, int b, int c, int d) {
		number = a;
		start = b;
		order = c;
		t = d;
	}
	bool operator<(const process p) const{
		if (order - start != p.order - p.start) {
			return order - start < p.order - p.start;
		}
		else {
			if (t != p.t) {
				return t > p.t;
			}
			else {
				return number > p.number;
			}
		}
	}
};
vector<int> ans;
vector<process> vec;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	priority_queue<process> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, p, b;
		cin >> t >> p >> b;
		vec.push_back({ i, t, p, b });;
		//pq.push({ i, t, p, b });
	}
	nowTime = 0;
	int index = 0;
	while (ans.size() != n) {
		while (index < n) {
			if (pq.size() == 0 && nowTime < vec[index].start) {
				nowTime = vec[index].start;
				pq.push(vec[index++]);
			}
			if (nowTime < vec[index].start) {
				break;
			}
			pq.push(vec[index++]);
		}
		process now = pq.top();
		pq.pop();
		nowTime += now.t;
		ans.push_back(now.number + 1);
	}
	for (auto k : ans) {
		cout << k << " ";
	}
	return 0;
}