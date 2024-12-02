/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 19:21:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    vector<int> a, b;
    while (cin >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = (int)a.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans;
}
