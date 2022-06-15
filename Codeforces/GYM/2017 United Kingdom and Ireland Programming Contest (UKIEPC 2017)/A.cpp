/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 19:32:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> h(n), r(n), t(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> r[i] >> t[i];
    }
    auto night = [&](int k, int j) {
        if (r[j] < t[j]) {
            return !(r[j] < k && k < t[j]);
        } else {
            return !((r[j] < k && k < h[j]) || (k < t[j]));
        }
    };
    int x = *max_element(h.begin(), h.end());
    for (int i = 0; i <= 1825 * x; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            ok &= night(i % h[j], j);
        }
        if (ok) {
            cout << i;
            return 0;
        }
    }
    cout << "impossible";
}
