/**
 *    author:  MaGnsi0
 *    created: 30.01.2024 16:54:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i].second << " ";
        }
        cout << "\n";
    }
}
