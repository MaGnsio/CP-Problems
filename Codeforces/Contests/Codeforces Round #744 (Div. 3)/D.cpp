/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 16:19:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!x) {
                continue;
            }
            s.insert({x, i + 1});
        }
        vector<pair<int, int>> res;
        while (s.size() > 1) {
            pair<int, int> a = *s.begin(), b = *s.rbegin();
            res.push_back({a.second, b.second});
            s.erase(a);
            a.first--;
            if (a.first) {
                s.insert(a);
            }
            s.erase(b);
            b.first--;
            if (b.first) {
                s.insert(b);
            }
        }
        cout << res.size() << "\n";
        for (auto& [x, y] : res) {
            cout << x << " " << y << "\n";
        }
    }
}
