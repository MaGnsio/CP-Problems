//https://codeforces.com/contest/1512/problem/E
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int k = r - l + 1;
        if (!(k * (k + 1) / 2 <= s && k * (2 * n - k + 1) / 2 >= s)) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> v;
        unordered_set<int> _s;
        for (int i = n; i > 0 && k > 0; --i) {
            if (k * (k - 1) / 2 <= s - i && i * (2 * n - i + 1) / 2 >=  s) {
                v.push_back (i);
                _s.insert (i);
                s -= i;
                k--;
            }
        }
        for (int i = 1; i < l; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (_s.count (j)) continue;
                _s.insert (j);
                cout << j << " ";
                break;
            }
        }
        for (auto& x : v)
            cout << x << " ";
        for (int i = r + 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (_s.count (j)) continue;
                _s.insert (j);
                cout << j << " ";
                break;
            }
        }
        cout << "\n";
    }
}

