/**
 *    author:  MaGnsi0
 *    created: 07.10.2021 17:54:48
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
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(((a[i] + i) % n + n) % n);
        }
        cout << (((int)s.size() == n && *s.begin() == 0 && *s.rbegin() == n - 1) ? "YES\n" : "NO\n");
    }
}
