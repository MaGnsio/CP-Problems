/**
 *    author:  MaGnsi0
 *    created: 23.12.2025 17:11:22
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
        sort(a.begin(), a.end());
        cout << (a[1] - a[0] > a[0] ? a[1] - a[0] : a[0]) << "\n";
    }
}
