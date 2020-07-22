#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str;
int t;
int g[5005];
int ng[5005];
int suf[5005];
int lcp[5005];
int rnk[5005];
int ans;
bool bigyo(int a, int b) {
	if (g[a] == g[b]) {
		return g[a + t] < g[b + t];
	}
	else {
		return g[a] < g[b];
	}
}
void func() {
	for (int i = 0; i < str.length(); i++) {
		suf[i] = i;
		g[i] = str[i] - 'a';
	}
	g[str.length()] = -1;
	for (t = 1; t < str.length(); t *= 2) {
		sort(suf, suf + str.length(), bigyo);
		ng[suf[0]] = 0;
		ng[str.length()] = -1;
		for (int i = 1; i < str.length(); i++) {
			if (bigyo(suf[i - 1], suf[i])) {
				ng[suf[i]] = ng[suf[i - 1]] + 1;
			}
			else {
				ng[suf[i]] = ng[suf[i - 1]];
			}
		}
		for (int i = 0; i < str.length(); i++) {
			g[i] = ng[i];
		}
	}
}
void lcp_func() {
	for (int i = 0; i < str.length(); i++) {
		rnk[suf[i]] = i;
	}
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		int k = rnk[i];
		if (k == 0) {
			continue;
		}
		int j = suf[k - 1];
		while (i + temp < str.length() && j + temp < str.length() && str[i + temp] == str[j + temp]) {
			temp++;
		}
		ans = max(ans, temp);
		if (temp > 0) {
			temp--;
		}
	}
}
int main() {
	cin >> str;
	func();
	lcp_func();
	cout << ans << endl;
	return 0;
}