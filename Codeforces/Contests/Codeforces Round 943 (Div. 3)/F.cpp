/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:52:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] ^ a[i - 1];
        }
        map<int, set<int>> pos;
        for (int i = 0; i <= n; ++i) {
            pos[p[i]].insert(i);
        }
        while (Q--) {
            int low; cin >> low; low--;
            int high; cin >> high;
            if (p[high] == p[low]) {
                cout << "YES\n";
                continue;
            }
            auto it1 = pos[p[high]].upper_bound(low);
            if (it1 == pos[p[high]].end()) {
                cout << "NO\n";
                continue;
            }
            int x1 = *it1;
            auto it2 = pos[p[low]].upper_bound(x1);
            if (it2 == pos[p[low]].end() || *it2 > high) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
    }
}
