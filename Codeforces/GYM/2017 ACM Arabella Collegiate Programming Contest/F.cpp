/**
 *    author:  MaGnsi0
 *    created: 06.07.2023 20:26:50
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m), c(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i] >> b[i] >> c[i];
        }
        int ans = n;
        set<int> s1;
        vector<set<int>> s2(M);
        for (int i = 0; i < n; ++i) {
            s1.insert(i);
        }
        for (int i = m - 1; i >= 0; --i) {
            int low = max(0, a[i] - c[i] - 1);
            int high = min(n - 1, a[i] + c[i] - 1);
            {
                auto it = s2[b[i]].lower_bound(low);
                while (it != s2[b[i]].end() && *it <= high) {
                    s2[b[i]].erase(it);
                    it = s2[b[i]].lower_bound(low);
                    ans++;
                }
            }
            {
                auto it = s1.lower_bound(low);
                while (it != s1.end() && *it <= high) {
                    s2[b[i]].insert(*it);
                    s1.erase(it);
                    it = s1.lower_bound(low);
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
}
