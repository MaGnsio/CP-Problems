/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 18:32:52
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
            cin >> a[i]; a[i]--;
        }
        string s; cin >> s;
        vector<int> ans(n);
        vector<bool> done(n, false);
        for (int i = 0; i < n; ++i) {
            if (done[i]) { continue; }
            int v = i, val = 0;
            vector<int> comp;
            while (!done[v]) {
                done[v] = true;
                val += s[v] == '0';
                comp.push_back(v);
                v = a[v];
            }
            for (int u : comp) {
                ans[u] = val;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
