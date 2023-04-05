/**
 *    author:  MaGnsi0
 *    created: 08.12.2022 17:59:01
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
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    int m;
    cin >> m;
    vector<int64_t> b(n, 0);
    for (int i = 0; i < m; ++i) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            int64_t x;
            cin >> x;
            auto it = s.lower_bound(k - 1); 
            while (x && it != s.end()) {
                int j = *it;
                if (a[j] - b[j] <= x) {
                    x -= a[j] - b[j];
                    b[j] = a[j];
                    s.erase(j);
                } else {
                    b[j] += x;
                    x = 0;
                }
                it = s.lower_bound(j + 1);
            }
        } else {
            cout << b[k - 1] << "\n";
        }
    }
}
