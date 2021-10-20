//https://codeforces.com/contest/1512/problem/D
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        n += 2;
        vector<long long> v(n), dp(n);
        for (auto& x : v)
            cin >> x;
        sort (v.begin (), v.end ());
        dp[0] = v[0];
        for (long long i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + v[i];
        }
        int chk = 0;
        for (long long i = 0; i < n - 1; ++i) {
            long long temp = (i ? dp[i - 1] : 0) + (dp[n - 2] - dp[i]);
            if (temp == v[n - 1]) {
                v[i] = v[n - 1] = -1;
                chk = 1;
                break;
            }
        }
        if (chk) {
            for (auto& x : v) {
                if (x == -1) continue;
                cout << x << " ";
            }
            cout << "\n";
            continue;
        }
        if (v[n - 2] == dp[n - 3]) {
            v[n - 2] = v[n - 1] = -1;
            chk = 1;
        }
        if (chk) {
            for (auto& x : v) {
                if (x == -1) continue;
                cout << x << " ";
            }
            cout << "\n";
            continue;
        }
        cout << -1 << "\n";
    }
}

