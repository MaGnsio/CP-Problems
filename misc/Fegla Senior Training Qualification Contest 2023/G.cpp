/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 14:57:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    multiset<int> s(a.begin(), a.end()), t;
    for (int i = 0; i < n; ++i) {
        t.insert(-a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int low = 0, high = k, x = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto it = s.lower_bound(b[i] + mid);
            if (it != s.end() && *it - b[i] <= k) {
                x = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (x != -1) {
            s.erase(s.find(b[i] + x));
            t.erase(t.find(-(b[i] + x)));
            ans++;
        } else {
            auto it = t.lower_bound(-b[i]);
            if (it == t.end()) {
                continue;
            }
            int x = -*it;
            if (b[i] - x > k) {
                continue;
            }
            s.erase(s.find(x));
            t.erase(it);
            ans++;
        }
    }
    cout << ans;
}
