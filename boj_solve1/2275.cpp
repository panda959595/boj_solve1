#include <iostream>
#include <vector>
using namespace std;
struct edge {
	int childNum;
	int len;
	int accumulateLen;
};
vector<edge> child[10005];
int n, h;
int root;
int ans = 0;
int calcAccumulateLen(int num) {
	int ret = 0;
	for (auto k : child[num]) {
		k.accumulateLen = calcAccumulateLen(k.childNum) + k.len;
		if (k.accumulateLen > h) {
			ans += min(k.accumulateLen - h, k.accumulateLen);
			k.accumulateLen -= min(k.accumulateLen - h, k.accumulateLen);
		}
		ret = max(ret, k.accumulateLen);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> h;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			root = i;
			continue;
		}
		edge temp;
		temp.childNum = i;
		temp.len = b;
		temp.accumulateLen = 0;
		child[a].push_back(temp);
	}
	for (auto k : child[root]) {
		k.accumulateLen = calcAccumulateLen(k.childNum) + k.len;
		if (k.accumulateLen > h) {
			ans += min(k.accumulateLen - h, k.accumulateLen);
		}
	}
	cout << ans << "\n";
	return 0;
}