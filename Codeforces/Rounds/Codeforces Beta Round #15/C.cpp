/**
 *    author:  MaGnsi0
 *    created: 22.09.2022 05:21:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int64_t(int64_t)> Xor = [](int64_t x) {
        if (x % 4 == 0) {
            return x;
        } else if (x % 4 == 1) {
            return int64_t(1);
        } else if (x % 4 == 2) {
            return x + 1;
        } else {
            return int64_t(0);
        }
    };
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        int64_t x, m;
        cin >> x >> m;
        a[i] = Xor(x + m - 1) ^ Xor(x - 1);
    }
    int64_t nimber = 0;
    for (int i = 0; i < n; ++i) {
        nimber ^= a[i];
    }
    cout << (nimber ? "tolik" : "bolik");
}
