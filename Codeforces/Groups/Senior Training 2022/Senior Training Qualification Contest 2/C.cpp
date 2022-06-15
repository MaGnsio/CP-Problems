/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 19:28:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("nearest.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> sp, sn;
        map<int, int> mp;
        sp.insert(a[0]);
        sn.insert(-a[0]);
        mp[a[0]] = 1;
        for (int i = 1; i < n; ++i) {
            auto it = sp.lower_bound(a[i]);
            int ans = -1;
            if (it != sp.end()) {
                ans = mp[*it];
            } else {
                ans = mp[*sp.rbegin()];
            }
            it = sp.upper_bound(a[i]);
            if (it != sp.end()) {
                if ((abs(a[i] - *it) < abs(a[i] - a[ans - 1])) || (abs(a[i] - *it) == abs(a[i] - a[ans - 1]) && mp[*it] < ans)) {
                    ans = mp[*it];
                }
            }
            it = sn.lower_bound(-a[i]);
            if (it != sn.end()) {
                if ((abs(a[i] - -1 * (*it)) < abs(a[i] - a[ans - 1])) || (abs(a[i] - -1 * (*it)) == abs(a[i] - a[ans - 1]) && mp[-1 * (*it)] < ans)) {
                    ans = mp[-1 * (*it)];
                }
            }
            it = sn.upper_bound(-a[i]);
            if (it != sn.end()) {
                if ((abs(a[i] - -1 * (*it)) < abs(a[i] - a[ans - 1])) || (abs(a[i] - -1 * (*it)) == abs(a[i] - a[ans - 1]) && mp[-1 * (*it)] < ans)) {
                    ans = mp[-1 * (*it)];
                }
            }
            cout << ans << " ";
            sp.insert(a[i]);
            sn.insert(-a[i]);
            if (mp.count(a[i]) == 0) {
                mp[a[i]] = i + 1;
            }
        }
        cout << "\n";
    }
}
