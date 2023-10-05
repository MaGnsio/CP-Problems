/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 22:24:40
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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        for (auto& [x, y] : a) {
            if (x > k) {
                break;
            }
            k += y;
        }
        cout << k << "\n";
    }
}
