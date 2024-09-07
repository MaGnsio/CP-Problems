/**
 *    author:  MaGnsi0
 *    created: 07.09.2024 15:13:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<set<int>> RP(n), RN(n), CP(m), CN(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            RP[i].insert(+j);
            RN[i].insert(-j);
            CP[j].insert(+i);
            CN[j].insert(-i);
        }
    }
    for (int i = 0; i < k; ++i) {
        int r; cin >> r; r--;
        int c; cin >> c; c--;
        if (RP[r].count(c)) {
            RP[r].erase(+c);
            RN[r].erase(-c);
            CP[c].erase(+r);
            CN[c].erase(-r);
            continue;
        }
        {
            auto it = RP[r].lower_bound(c);
            if (it != RP[r].end()) {
                int c_ = *it;
                RP[r].erase(+c_);
                RN[r].erase(-c_);
                CP[c_].erase(+r);
                CN[c_].erase(-r);
            }
        }
        {
            auto it = RN[r].lower_bound(-c);
            if (it != RN[r].end()) {
                int c_ = -*it;
                RP[r].erase(+c_);
                RN[r].erase(-c_);
                CP[c_].erase(+r);
                CN[c_].erase(-r);
            }
        }
        {
            auto it = CP[c].lower_bound(r);
            if (it != CP[c].end()) {
                int r_ = *it;
                RP[r_].erase(+c);
                RN[r_].erase(-c);
                CP[c].erase(+r_);
                CN[c].erase(-r_);
            }
        }
        {
            auto it = CN[c].lower_bound(-r);
            if (it != CN[c].end()) {
                int r_ = -*it;
                RP[r_].erase(+c);
                RN[r_].erase(-c);
                CP[c].erase(+r_);
                CN[c].erase(-r_);
            }
        }
    }
    int ans = 0;
    for (auto s : RP) {
        ans += (int)s.size();
    }
    cout << ans;
}
