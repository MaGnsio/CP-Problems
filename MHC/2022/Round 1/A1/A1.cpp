/**
 *    author:  MaGnsi0
 *    created: 10.09.2022 19:59:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            c[b[i] - 1] = i;
        }
        set<int> shifts;
        for (int i = 0; i < n; ++i) {
            shifts.insert(c[a[i] - 1] >= i ? c[a[i] - 1] - i : c[a[i] - 1] + n - i);
        }
        cout << "Case #" << t << ": ";
        cout << (((int)shifts.size() != 1 || (*shifts.begin() == 0 && k == 1) || (*shifts.begin() != 0 && k == 0) || (n == 2 && *shifts.begin() == 0 && k % 2 != 0) || (n == 2 && *shifts.begin() == 1 && k % 2 == 0)) ? "NO" : "YES") << "\n";
    }
}
