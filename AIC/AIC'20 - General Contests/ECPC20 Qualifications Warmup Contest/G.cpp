//https://codeforces.com/group/nVgev28wQI/contest/303358/problem/G
#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b) {
    return (b ? gcd (b, a % b)  : a);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n;
    cin >> n;
    vector<long long> v(n), pre(n), suf(n);
    for (auto& x : v) cin >> x;
    pre[0] = v[0];
    for (long long i = 1; i < n; ++i) {
        pre[i] = v[i] * (pre[i - 1] / gcd (v[i], pre[i - 1]));
    }
    suf[n - 1] = v[n - 1];
    for (long long i = n - 2; i >= 0; --i) {
        suf[i] = v[i] * (suf[i + 1] / gcd (v[i], suf[i + 1]));
    }
    long long ans = pre[n - 1];
    for (long long i = 0; i < n; ++i) {
        if (!i)
            ans = min (ans, suf[i + 1]);
        else if (i == n - 1)
            ans = min (ans, pre[i - 1]);
        else
            ans = min (ans, pre[i - 1] * (suf[i + 1] / gcd (pre[i - 1], suf[i + 1])));
    }
    cout << ans;
}

