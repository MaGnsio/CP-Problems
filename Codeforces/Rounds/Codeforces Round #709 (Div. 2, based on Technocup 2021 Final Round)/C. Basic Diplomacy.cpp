//https://codeforces.com/contest/1484/problem/C
#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m);
        for (int i = 0; i < m; ++i) {
            int k;
            cin >> k;
            v[i].resize (k);
            for (auto& x : v[i]) cin >> x;
        }

        vector<int> f(n + 1, 0), ans(m, 0);
        for (int i = 0; i < m; ++i) {
            int x = v[i][0];
            ans[i] = x;
            f[x]++;
        }
        for (int i = 0; i < m; ++i) {
            if (f[ans[i]] <= (m + 1) / 2) continue;
            for (auto& x : v[i]) {
                if (x != ans[i] && f[x] < (m + 1) / 2) {
                    f[ans[i]]--;
                    ans[i] = x;
                    f[x]++;
                    break;
                }
            }
        }

        bool chk = true;
        for (int i = 0; i < m; ++i) {
            if (f[ans[i]] > (m + 1) / 2) {
                chk = false;
                break;
            }
        }

        if (chk) {
            cout << "YES\n";
            for (int i = 0; i < m; ++i)
                cout << ans[i] << " ";
            cout << "\n";
        }
        else
            cout << "NO\n";
    }
}
