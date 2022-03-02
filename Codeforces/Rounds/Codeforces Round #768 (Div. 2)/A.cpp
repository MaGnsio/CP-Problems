/**
 *    author:  MaGnsi0
 *    created: 05.02.2022 20:37:11
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
        vector<pair<int, int>> a(2 * n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[n + i].first;
            a[n + i].second = i;
        }
        sort(a.begin(), a.end());
        set<int> s;
        vector<int> b, c;
        for (int i = 0; i < 2 * n; ++i) {
            if (s.count(a[i].second)) {
                b.push_back(a[i].first);
            } else {
                c.push_back(a[i].first);
                s.insert(a[i].second);
            }
        }
        cout << b[n - 1] * c[n - 1] << "\n";
    }
}
