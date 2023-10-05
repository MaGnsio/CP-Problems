/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 17:52:27
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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i].second] = (i == n - 1 ? a[i].first - a[i - 1].first : a[i].first - a[n - 1].first);
        }
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
}
