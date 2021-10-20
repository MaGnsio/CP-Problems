//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/D
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, sum = 0;
    cin >> n;
    vector<long long> v(n), dp(n);
    for (auto& x : v)
        cin >> x;
    sort (v.begin (), v.end (), greater<long long> ());
    dp[0] = v[0];
    for (long long i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + v[i];
    }
    for (long long i = 0; i < n; ++i) {
        sum += v[i] * (n - i - 1) - (dp[n - 1] - dp[i]);
    }
    cout << sum;
}

