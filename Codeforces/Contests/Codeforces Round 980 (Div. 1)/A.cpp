/**
 *    author:  MaGnsi0
 *    created: 20.10.2024 19:19:08
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
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first + p1.second < p2.first + p2.second;
        });
        for (auto [x, y] : a) {
            cout << x << " " << y << " ";
        }
        cout << "\n";
    }
}
