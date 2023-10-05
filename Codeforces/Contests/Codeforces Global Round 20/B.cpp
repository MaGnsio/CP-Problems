/**
 *    author:  MaGnsi0
 *    created: 23.04.2022 15:57:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<int> b;
        set<int> a;
        if (s[(int)s.size() - 1] != 'B') {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == 'A') {
                a.insert(-i);
            } else {
                b.push_back(i);
            }
        }
        if (a.empty() || b.empty()) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        for (int i = (int)b.size() - 1; i >= 0; --i) {
            auto it = a.lower_bound(-b[i]);
            if (it == a.end()) {
                ok = false;
                break;
            }
            a.erase(it);
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
