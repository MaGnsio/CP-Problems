/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 16:56:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int m; cin >> m;
        string s; cin >> s;
        int group = 0;
        string bad = "";
        set<int> need;
        for (int j = 0; j < k; ++j) {
            need.insert(j);
        }
        for (int i = 0; i < m; ++i) {
            need.erase(s[i] - 'a');
            if (need.empty()) {
                bad += s[i];
                for (int j = 0; j < k; ++j) {
                    need.insert(j);
                }
                group++;
            }
        }
        if (group >= n) {
            cout << "YES\n";
            continue;
        } else {
            cout << "NO\n";
            cout << bad << string(n - (int)bad.size(), char('a' + *need.begin())) << "\n";
        }
    }
}
