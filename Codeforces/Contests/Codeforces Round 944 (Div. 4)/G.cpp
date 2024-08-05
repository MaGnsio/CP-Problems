/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:57:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (x & 1) { x ^= 1; }
            if (x & 2) { x ^= 2; }
            mp[x].push_back(a[i]);
            a[i] = x;
        }
        for (auto& [_, b] : mp) {
            sort(b.rbegin(), b.rend());
        }
        for (int i = 0; i < n; ++i) {
            cout << mp[a[i]].back() << " ";
            mp[a[i]].pop_back();
        }
        cout << "\n";
    }
}
