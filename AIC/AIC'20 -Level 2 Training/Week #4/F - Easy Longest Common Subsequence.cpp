//https://vjudge.net/contest/433102#problem/F
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int ans = 0;
    string a, b;
    cin >> a >> b;
    int n = a.size (), m = b.size ();
    for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << m); ++mask2) {
            if (__builtin_popcount (mask1) != __builtin_popcount (mask2)) {
                continue;
            }
            string s = "", t = "";
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & mask1) {
                    s.push_back (a[j]);
                }
            }
            for (int j = 0; j < m; ++j) {
                if ((1 << j) & mask2) {
                    t.push_back (b[j]);
                }
            }
            if (s == t) ans = max (ans, __builtin_popcount (mask1));
        }
    }
    cout << ans;
}

