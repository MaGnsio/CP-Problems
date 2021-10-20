//https://codeforces.com/contest/1513/problem/B
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> v(n), b(64, 0);
        for (auto& x : v) {
            cin >> x;
            for (long long i = 0; i < 64; ++i) {
                b[i] += (x >> i) & 1;
            }
        }
        long long k = 0;
        for (long long i = 0; i < 64; ++i) {
            if (b[i] == n) {
                k += (1 << i);
            }
        }
        long long cnt = count (v.begin (), v.end (), k);
        if (cnt < 2) {
            cout << 0 << "\n";
            continue;
        }
        long long ans = 1, x = ((cnt % mod) * ((cnt - 1) % mod)) % mod;
        for (long long i = 1; i <= n - 2; ++i) {
            ans = ((ans % mod) * (i % mod)) % mod;
        }
        ans = ((ans % mod) * (x % mod)) % mod;
        cout << ans << "\n";
    }
}

