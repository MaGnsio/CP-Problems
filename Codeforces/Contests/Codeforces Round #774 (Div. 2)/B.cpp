/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 19:23:32
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
        sort(a.begin(), a.end());
        int l = 2, r = n - 2;
        long long B = a[0] + a[1], R = a[n - 1];
        bool ok = (R > B);
        while (l < r) {
            B += a[l++], R += a[r--];
            ok |= (R > B);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
