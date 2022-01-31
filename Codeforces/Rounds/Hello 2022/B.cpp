/**
 *    author:  MaGnsi0
 *    created: 03.01.2022 16:27:21
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
        vector<int> l(n), r(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i] >> c[i];
        }
        set<pair<int, pair<int, int>>> low;
        set<pair<int, pair<int, int>>> high;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; ++i) {
            low.insert({l[i], {c[i], i}});
            high.insert({-r[i], {c[i], i}});
            if (mp.find(make_pair(l[i], r[i])) != mp.end()) {
                mp[{l[i], r[i]}] = min(mp[{l[i], r[i]}], c[i]);
            } else {
                mp[{l[i], r[i]}] = c[i];
            }
            pair<int, pair<int, int>> mini = *low.begin();
            pair<int, pair<int, int>> maxi = *high.begin();
            int res = mini.second.first + (mini.second.second != maxi.second.second) * maxi.second.first;
            if (mp.find(make_pair(mini.first, -maxi.first)) != mp.end()) {
                res = min(res, mp[{mini.first, -maxi.first}]);
            }
            cout << res << "\n";
        }
    }
}
