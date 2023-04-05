/**
 *    author:  MaGnsi0
 *    created: 13.11.2022 20:31:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[j] >= a[i]) {
                mp[b[j] - a[i]]++;
            }
        }
    }
    int ans = -1, time = -1;
    for (auto& [x, y] : mp) {
        if (y > ans) {
            ans = y;
            time = x;
        }
    }
    cout << max(time, 0);
}
