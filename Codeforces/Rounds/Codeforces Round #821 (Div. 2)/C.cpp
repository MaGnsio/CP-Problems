/**
 *    author:  MaGnsi0
 *    created: 19.09.2022 16:32:53
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
            a[i] %= 2;
        }
        if (n == 1) {
            cout << 0 << "\n";
            continue;
        }
        cout << n - 1 << "\n";
        cout << 1 << " " << n << "\n";
        for (int i = 2; i < n; ++i) {
            int l = i, r;
            if (a[0] == 1) {
                r = (a[i - 1] == 1 ? n : 1);
            } else {
                r = (a[i - 1] == 1 ? 1 : n);
            }
            if (l > r) {
                swap(l, r);
            }
            cout << l << " " << r << "\n";
        }
    }
}
