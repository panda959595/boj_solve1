#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
long long s, e;
struct stru {
    int destination;
    long long len;
    bool jam;
};
vector<stru> road[5005];
bool check[5005];
long long ans[5005];
long long func(long long start, stru street) {  // 진입시간, 도로, return : 도착시간
    if (!street.jam) {
        return start + street.len;
    }
    if (start + street.len <= s || start >= e) {
        return start + street.len;
    }
    if (start < s) {
        long long ret = start;
        long long len = street.len;
        len -= s - start;
        ret += s - start;
        if (len <= (e - s) / 2) {
            return ret + len * 2;
        }
        else {
            return ret + (e - s) + len - (e - s) / 2;
        }
    }
    else {
        long long ret = start;
        long long len = street.len;
        if (len <= (e - start) / 2) {
            return ret + len * 2;
        }
        else {
            return ret + (e - start) + len - (e - start) / 2;
        }
    }
}
int main() {
    cin >> n >> m >> s >> e;
    s *= 2;
    e *= 2;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long l;
        bool c, d;
        cin >> a >> b >> l >> c >> d;
        l *= 2;
        road[a].push_back({ b, l, c });
        road[b].push_back({ a, l, d });
    }
    for (int i = 0; i <= n; i++) {
        ans[i] = 9223372036854775806;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;// 시간, 정점
    pq.push({ 0,1 });
    while (!pq.empty()) {
        pair<long long, int>  now = pq.top();
        pq.pop();
        if (now.first > ans[now.second]) {
            continue;
        }
        ans[now.second] = now.first;
        for (auto k : road[now.second]) {
            if (check[k.destination]) {
                continue;
            }
            pq.push({ func(now.first,k), k.destination });
        }
    }
    long long output = 0;
    for (int i = 1; i <= n; i++) {
        output = max(output, ans[i]);
    }
    if (output % 2 == 0) {
        cout << output / 2 << endl;
    }
    else {
        cout << output / 2 << ".5" << endl;
    }
    /*double temp = output / 2;
    if (output % 2 != 0) {
        temp += 0.5;
    }
    cout << temp << endl;*/
    return 0;
}