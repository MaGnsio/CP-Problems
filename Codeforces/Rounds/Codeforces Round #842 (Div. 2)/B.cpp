/**
 *    author:  MaGnsi0
 *    created: 06.01.2023 16:41:16
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
            cnt += a[i] == cnt + 1;
        }
        cout << (n - cnt + k - 1) / k << "\n";
    }
}
