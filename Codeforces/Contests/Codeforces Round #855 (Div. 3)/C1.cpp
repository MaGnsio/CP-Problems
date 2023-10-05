/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 20:43:44
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0;
        multiset<int64_t> s;
        for (int i = 0; i < n; ++i) {
            if (a[i]) { s.insert(a[i]); continue; }
            if (s.empty()) { continue; }
            int x = *s.rbegin();
            ans += x;
            s.erase(s.find(x));
        }
        cout << ans << "\n";
    }
}
