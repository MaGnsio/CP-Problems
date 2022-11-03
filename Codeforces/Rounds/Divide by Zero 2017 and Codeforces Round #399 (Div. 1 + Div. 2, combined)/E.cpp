/**
 *    author:  MaGnsi0
 *    created: 27.09.2022 21:55:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<pair<int, int64_t>, int> grundy;
    function<int(int, int64_t)> F = [&](int x, int64_t picked) {
        pair<int, int64_t> k = make_pair(x, picked);
        if (grundy.count(k)) {
            return grundy[k];
        }
        set<int> s;
        for (int i = 1; i <= x; ++i) {
            if (picked & (int64_t(1) << i)) {
                continue;
            }
            s.insert(F(x - i, picked | (int64_t(1) << i)));
        }
        grundy[k] = 0;
        while (s.count(grundy[k])) {
            grundy[k]++;
        }
        return grundy[k];
    };
    int nimber = 0;
    for (int i = 0; i < n; ++i) {
        nimber ^= F(a[i], 0);
    }
    cout << (nimber ? "NO" : "YES");
}
