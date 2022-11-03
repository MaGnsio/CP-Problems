/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 13:56:51
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x]++;
    }
    if (m.size() == 1) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    vector<int> pre;
    for (auto& [x, y] : m) {
        pre.push_back(y);
    }
    for (int i = 1; i < pre.size(); ++i) {
        pre[i] += pre[i - 1];
    }
    for (int i = 0; i < pre.size(); ++i) {
        ans += (pre[i] - (i ? pre[i - 1] : 0)) * (pre[pre.size() - 1] - pre[i] + (i ? pre[i - 1] : 0));
    }
    cout << ans / 2;
}
