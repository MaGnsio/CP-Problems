/**
 *    author:  MaGnsi0
 *    created: 12.02.2022 16:29:56
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        bool ok = false;
        for (int i = 0; i < n - 1; ++i) {
            s.erase(s.find(a[i]));
            if (*s.begin() < a[i]) {
                ok = true;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
