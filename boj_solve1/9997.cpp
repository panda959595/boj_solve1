#include <iostream>
#include <string>
using namespace std;
const int flag = 67108863;
int arr[26];
bool inout[26];
int ans;
int n;
int check;
void func(int num) {
	if (num == n) {
		if (check == flag) {
			ans++;
		}
		return;
	}
	func(num + 1);
	inout[num] = true;
	int temp = check;
	check |= arr[num];
	func(num + 1);
	check = temp;
	inout[num] = false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			arr[i] |= 1 << (temp[j] - 'a');
		}
	}
	func(0);
	cout << ans << endl;
	return 0;
}