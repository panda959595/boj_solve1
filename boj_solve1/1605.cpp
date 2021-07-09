#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string str;
int lcp[200005];
int sa[200005];
int group[200005];
int t;
int n;
int temp[200005];
int rnk[200005];
bool compare(int a, int b) {
	if (group[a] == group[b]) {
		return group[a + t] < group[b + t];
	}
	return group[a] < group[b];
}
void funcSA() {
	t = 1;
	for (int i = 0; i < n; i++) {
		group[i] = str[i] - 'a';
		sa[i] = i;
	}
	while (t <= n) {
		group[n] = -1;
		sort(sa, sa + n, compare);
		temp[sa[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (compare(sa[i - 1], sa[i])) {
				temp[sa[i]] = temp[sa[i - 1]] + 1;
			}
			else {
				temp[sa[i]] = temp[sa[i - 1]];
			}
		}

		for (int i = 0; i < n; i++) {
			group[i] = temp[i];
		}
		t <<= 1;
	}
}
void funcLCP() {
	for (int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	int len = 0;
	for (int i = 0; i < n; i++) {
		int j = rnk[i];
		if (j == 0) {
			continue;
		}
		int k = sa[j - 1];
		while (str[i + len] == str[k + len]) {
			len++;
		}
		lcp[j] = len;
		
		if (len > 0) {
			len--;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> str;
	funcSA();
	funcLCP();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(lcp[i], ans);
	}
	cout << ans << "\n";
	return 0;
}