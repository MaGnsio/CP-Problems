//https://vjudge.net/contest/433102#problem/M
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0;
        bitset<1024> b;
        cin >> n >> m;
        b.set ();
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            b.reset (x - 1);
        }
        for (int i = (1 << n); i; i >>= 1) {
            int idx = 0;
            for (int j = 1; j < i; j += 2) {
                ans += (b[j] ^ b[j - 1]);
                b[idx++] = (b[j] | b[j - 1]);
            }
        }
        cout << ans << "\n";
    }
}

