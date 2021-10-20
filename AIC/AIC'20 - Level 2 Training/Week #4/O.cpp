//https://vjudge.net/contest/433102#problem/O
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n, ans = 0;
        cin >> n;
        for (long long i = 0; i < 64; ++i) {
            if ((1LL << i) & n) {
                ans += (1LL << (i + 1)) - 1;
            }
        }
        //ans = 2 * n - __builtin_popcount (n)
        cout << ans << "\n";
    }
}

