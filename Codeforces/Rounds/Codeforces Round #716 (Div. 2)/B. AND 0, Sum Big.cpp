//https://codeforces.com/contest/1514/problem/B
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n, k, ans = 1;
        cin >> n >> k;
        for (long long i = 0; i < k; ++i) {
            ans = ((ans % mod) * (n % mod)) % mod;
        }
        cout << (ans % mod) << "\n";
    }
}

