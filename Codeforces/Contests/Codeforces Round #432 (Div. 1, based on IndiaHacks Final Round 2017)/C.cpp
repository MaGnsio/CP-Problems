/**
 *    author:  MaGnsi0
 *    created: 27.09.2022 19:38:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j * j <= a[i]; ++j) {
            int x = 0;
            while (a[i] % j == 0) {
                a[i] /= j;
                x++;
            }
            if (x) { mp[j] |= (1 << x); }
        }
        if (a[i] > 1) { mp[a[i]] |= 2; }
    }
    map<int, int> grundy;
    function<int(int)> F = [&](int x) {
        if (grundy.count(x)) {
            return grundy[x];
        }
        set<int> s;
        for (int i = 1; i <= 30; ++i) {
            if (x >= (1 << i)) {
                s.insert(F((x & ((1 << i) - 1)) | (x >> i)));
            }
        }
        grundy[x] = 0;
        while(s.count(grundy[x])) {
            grundy[x]++;
        }
        return grundy[x];
    };
    int nimber = 0;
    for (auto& [_, x] : mp) {
        nimber ^= F(x);
    }
    cout << (nimber ? "Mojtaba" : "Arpa");
}
