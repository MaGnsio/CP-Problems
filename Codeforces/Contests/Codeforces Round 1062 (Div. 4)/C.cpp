/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 17:40:15
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
            cin >> a[i];
        }
        bool have_odd = false;
        bool have_even = false;
        for (int i = 0; i < n; ++i) {
            have_odd |= a[i] % 2 == 1;
            have_even |= a[i] % 2 == 0;
        }
        if (have_odd && have_even) {
            sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
