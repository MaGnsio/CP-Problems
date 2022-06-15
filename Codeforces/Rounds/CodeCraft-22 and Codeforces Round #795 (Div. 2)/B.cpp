/**
 *    author:  MaGnsi0
 *    created: 01.06.2022 15:42:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]].push_back(i + 1);
        }
        bool ok = true;
        map<int, int> idx;
        for (auto& [x, y] : mp) {
            if (y.size() == 1) {
                ok = false;
            }
            idx[x] = 1;
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            cout << mp[a[i]][idx[a[i]]++ % (int)mp[a[i]].size()] << " ";
        }
        cout << "\n";
    }
}
