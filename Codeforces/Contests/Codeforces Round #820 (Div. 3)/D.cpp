/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:16
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
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        multiset<int64_t> pos, neg;
        for (int i = 0; i < n; ++i) {
            if (b[i] - a[i] >= 0) {
                pos.insert(-(b[i] - a[i]));
            } else {
                neg.insert(b[i] - a[i]);
            }
        }
        int ans = 0;
        while (true) {
            int64_t x = *pos.begin();
            auto it = neg.lower_bound(x);
            if (it == neg.end()) {
                break;
            }
            pos.erase(pos.find(x));
            neg.erase(neg.find(*it));
            ans++;
        }
        cout << ans + (int)pos.size() / 2 << "\n";
    }
}
