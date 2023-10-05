/**
 *    author:  MaGnsi0
 *    created: 30.12.2022 16:52:58
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            ok &= a[i] != a[i - 1];
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        bool bad = false;
        for (int i = 2; i <= n; ++i) {
            vector<int> mod(i);
            for (int j = 0; j < n; ++j) {
                mod[a[j] % i]++;
            }
            bool ok = true;
            for (int j = 0; j < i; ++j) {
                ok &= mod[j] >= 2;
            }
            if (ok) {
                bad = true;
                break;
            }
        }
        cout << (bad ? "NO\n" : "YES\n");
    }
}
