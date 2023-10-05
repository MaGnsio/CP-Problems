/**
 *    author:  MaGnsi0
 *    created: 16.10.2022 23:06:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << (count(a.begin(), a.end(), 1) > 0 ? "YES" : "NO") << "\n";
    }
}
