/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 21:14:18
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n == 1) {
            cout << (a[0] == 1 ? "YES" : "NO");
        } else {
            cout << (a[n - 1] - a[n - 2] < 2 ? "YES" : "NO");
        }
        cout << "\n";
    }
}
