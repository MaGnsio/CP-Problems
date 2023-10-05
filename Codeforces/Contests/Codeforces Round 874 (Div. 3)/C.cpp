/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 17:44:41
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
        set<int> evens, odds;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                evens.insert(-a[i]);
            } else {
                odds.insert(-a[i]);
            }
        }
        bool ok_even = true, ok_odd = true;
        for (int i = 0; i < n; ++i) {
            if (!((a[i] % 2 == 0) || (odds.upper_bound(-a[i]) != odds.end()))) {
                ok_even = false;
            }
            if (!((a[i] & 1) || (odds.upper_bound(-a[i]) != odds.end()))) {
                ok_odd = false;
            }
        }
        cout << (ok_even || ok_odd ? "YES" : "NO") << "\n";
    }
}
