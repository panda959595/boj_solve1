#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, h;
struct point {
    int x, y;
};
vector<point> milk;
point home;
int len(point u, point v) {
    return abs(u.x - v.x) + abs(u.y - v.y);
}
vector<int> vec;
int ans = 0;
void func() {
    point now = home;
    int energy = m;
    int eat = 0;
    for (int k : vec) {
        int work = len(now, milk[k]);
        if (energy < work) {
            break;
        }
        now = milk[k];
        energy -= work - h;
        eat++;
        if (len(now, home) <= energy) {
            ans = max(ans, eat);
        }
    }
}
int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                home.x = i;
                home.y = j;
            } else if (temp == 2) {
                milk.push_back({i, j});
                vec.push_back(vec.size());
            }
        }
    }
    do {
        func();
    } while (next_permutation(vec.begin(), vec.end()));
    cout << ans << endl;
    return 0;
}