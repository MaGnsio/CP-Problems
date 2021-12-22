/**
 *    author:  MaGnsi0
 *    created: 21.11.2021 15:33:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            mp[x] = {i, j};
        }
    }
    vector<int> r(n, 0), c(n, 0);
    for (int i = 0; i < n * n; ++i) {
        int x;
        cin >> x;
        r[mp[x].first]++;
        c[mp[x].second]++;
        for (int i = 0; i < n; ++i) {
            if (r[i] == n || c[i] == n) {
                cout << x;
                return 0;
            }
        }
    }
}
