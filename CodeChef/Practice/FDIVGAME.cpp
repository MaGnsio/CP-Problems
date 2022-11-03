/**
 *    author:  MaGnsi0
 *    created: 28.09.2022 17:33:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int64_t, int> grundy;
    grundy[0] = 0;
    function<int(int64_t)> F = [&](int64_t x) {
        if (grundy.count(x)) {
            return grundy[x];
        }
        if (x >= 12) {
            return F(x / 12);
        }
        set<int> s;
        for (int j = 2; j <= 6; ++j) {
            s.insert(F(x / j));
        }
        grundy[x] = 0;
        while (s.count(grundy[x])) {
            grundy[x]++;
        }
        return grundy[x];
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int nimber = 0;
        for (int i = 0; i < n; ++i) {
            nimber ^= F(a[i]);
        }
        cout << (nimber ? "Henry" : "Derek") << "\n"; 
    }
}
