#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > s;
vector<pair<int, int> > e;
vector<pair<int, int> > vec;
vector<int> flag;
int main() {
	int n, d;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		s.push_back({ min(a, b), i });
		e.push_back({ min(a, b), i });
		vec.push_back({ a, i });
		vec.push_back({ b, i });
		flag.push_back(0);
	}
	cin >> d;
	sort(s.begin(), s.end());
	sort(e.begin(), e.end());
	sort(vec.begin(), vec.end());
	int l, r;
	
	int ans = 0;
	int cnt = 0;
	l = r = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		while (l < vec.size() && vec[l].first < s[i].first) {
			flag[vec[l].second]--;
			if (flag[vec[l].second] == 1) {
				cnt--;
			}
			l++;
		}
		while (r < vec.size() && vec[r].first <= s[i].first + d) {
			flag[vec[r].second]++;
			if (flag[vec[r].second] == 2) {
				cnt++;
			}
			r++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}