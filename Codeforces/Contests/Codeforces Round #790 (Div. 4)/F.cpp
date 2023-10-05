/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int m = (int)a.size();
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            b[i] = (mp[a[i]] >= k);
            if (i) {
                b[i] += b[i - 1];
            }
        }
        int L = 0, R = m - 1, l = -1, r = -1;
        while (L <= R) {
            int M = (L + R) / 2;
            bool ok = false;
            for (int i = M; i < m; ++i) {
                if ((a[i] - a[i - M] + 1 == M + 1) && (b[i] - (i - M - 1 >= 0 ? b[i - M - 1] : 0) == M + 1)) {
                    l = a[i - M], r = a[i];
                    ok = true;
                }
            }
            if (ok) {
                L = M + 1;
            } else {
                R = M - 1;
            }
        }
        if (l == -1) {
            cout << -1;
        } else {
            cout << l << " " << r;
        }
        cout << "\n";
    }
}
