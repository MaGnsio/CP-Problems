//https://vjudge.net/contest/433102#problem/J
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s, t;
    cin >> s >> t;
    int x = 0, y = 0, a = 0, b = 0, c = 0, p = 0;
    for (auto& k : s) {
        x += (k == '+');
        y += (k == '-');
    }
    for (auto& k : t) {
        a += (k == '+');
        b += (k == '-');
        c += (k == '?');
    }
    for (int mask = 0; mask < (1 << c); ++mask) {
        int u = a, v = b;
        for (int j = 0; j < c; ++j) {
            if ((1 << j) & mask) {
                u++;
            }
            else {
                v++;
            }
        }
        if (u == x && v == y) {
            p++;
        }
    }
    double ans = p / double (1 << c);
    cout << fixed << setprecision (12) << ans;
}

