/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:16
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
        iota(a.begin(), a.end(), 3);
        int64_t last_e = 0, last_o = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (i & 1) {
                last_o ^= a[i];
            } else {
                last_e ^= a[i];
            }
        }
        assert(last_e != last_o);
        for (int i = 30; i >= 0; --i) {
            if (((last_e >> i) & 1) == ((last_o >> i) & 1)) {
                last_e |= (1LL << i);
                last_o |= (1LL << i);
            }
        }
        if (n & 1) {
            a[n - 1] = last_e;
            a[n - 2] = last_o;
        } else {
            a[n - 1] = last_o;
            a[n - 2] = last_e;
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
