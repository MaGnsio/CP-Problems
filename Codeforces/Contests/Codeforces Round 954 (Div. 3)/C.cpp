/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 18:01:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        string s; cin >> s;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i]; a[i]--;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        m = (int)a.size();
        string t; cin >> t;
        sort(t.begin(), t.end());
        for (int i = 0; i < m; ++i) {
            s[a[i]] = t[i];
        }
        cout << s << "\n";
    }
}
