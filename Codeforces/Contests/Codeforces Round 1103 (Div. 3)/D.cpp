/**
 *    author:  MaGnsi0
 *    created: 18.06.2026 19:25:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        map<int, int> f;
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; f[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        n = (int)a.size();
        bool win = false;
        for (int i = 0; i < n; ++i) {
            if (i + 1 == n || a[i + 1] - a[i] > k) {
                win |= f[a[i]] % 2 == 0;
                win |= (i && a[i] - a[i - 1] <= k && f[a[i]] % 2 == 1);
            }
        }
        cout << (win ? "YES" : "NO") << "\n";
    }
}
