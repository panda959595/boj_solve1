#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> vec;
	vector<int> pre;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
		pre.push_back(-1);
	}

	vector<int> lcs;
	vector<int> idx;
	for (int i = 0; i < n;i++) {
		int k = vec[i];
		if (lcs.size() == 0) {
			lcs.push_back(k);
			idx.push_back(i);
			pre[i] = -1;
			continue;
		}
		int index = lower_bound(lcs.begin(), lcs.end(), k) - lcs.begin();
		if (index == lcs.size()) {
			lcs.push_back(k);
			idx.push_back(i);
			pre[i] = idx[index - 1];
		}
		else {
			lcs[index] = k;
			idx[index] = i;
			if (index != 0) {
				pre[i] = idx[index - 1];
			}
		}
	}
	vector<int> ans;
	
	int index = idx[lcs.size() - 1];

	while (index != -1) {
		ans.push_back(vec[index]);
		index = pre[index];
	}

	cout << lcs.size() << endl;
	for (int i = lcs.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}

	return 0;
}