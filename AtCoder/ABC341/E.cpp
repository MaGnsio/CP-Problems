/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 14:22:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    string s; cin >> s;
    set<int> bad;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            bad.insert(i);
        }
    }
    while (Q--) {
        int t; cin >> t;
        int low; cin >> low; low--;
        int high; cin >> high; high--;
        if (t == 1) {
            if (bad.count(low - 1)) {
                bad.erase(low - 1);
            } else if (low) {
                bad.insert(low - 1);
            }
            if (bad.count(high)) {
                bad.erase(high);
            } else if (high + 1 < n) {
                bad.insert(high);
            }
        } else {
            auto it = bad.lower_bound(low);
            cout << ((it == bad.end() || *it + 1 > high) ? "Yes" : "No") << "\n";
        }
    }
}
