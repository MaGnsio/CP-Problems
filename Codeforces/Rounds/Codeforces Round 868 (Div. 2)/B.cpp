/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 18:03:28
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
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += a[i] % k != (i + 1) % k;
        }
        cout << (cnt == 0 ? 0 : (cnt == 2 ? 1 : -1)) << "\n";
    }
}
