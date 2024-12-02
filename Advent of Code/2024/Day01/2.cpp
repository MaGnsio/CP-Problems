/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 19:23:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    map<int, int> a, b;
    while (cin >> x >> y) {
        a[x]++, b[y]++;
    }
    int64_t ans = 0;
    for (auto [x, _] : a) {
        ans += x * b[x];
    }
    cout << ans;
}
