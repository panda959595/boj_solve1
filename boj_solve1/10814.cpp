#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct stru {
	int age;
	int index;
	string name;
};
stru arr[100'005];
bool compare(stru u, stru v) {
	if (u.age != v.age) {
		return u.age < v.age;
	}
	else {
		return u.index < v.index;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].index = i;
	}
	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
	return 0;
}