//https://vjudge.net/contest/433102#problem/K
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, s, ans = LLONG_MIN;
        cin >> n >> s;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
        }
        sort (v.begin (), v.end (), greater<int> ());
        for (int mask = 0; mask < (1 << n); ++mask) {
            bool chk = true;
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & mask) {
                    if (cur >= s) {
                        chk = false;
                        break;
                    }
                    else {
                        cur += v[j];
                    }
                }
            }
            if (chk && cur >= s) {
                ans = max (ans, __builtin_popcount (mask));
            }
        }
        cout << ans << "\n";
    }
}

