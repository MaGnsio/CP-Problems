/**
 *    author:  MaGnsi0
 *    created: 24.04.2023 16:41:47
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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << max(a[0] * a[1], a[n - 1] * a[n - 2]) << "\n";
    }
}
