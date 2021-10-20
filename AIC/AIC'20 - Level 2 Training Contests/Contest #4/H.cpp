//https://vjudge.net/contest/417537#problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, ans = 0;
    cin >> n;
    vector<long long> v(n), t(32, 0);
    for (auto& x : v) {
        cin >> x;
        x = __builtin_ctz (x);
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < v[i]; ++j) {
            ans += t[j];
        }
        t[v[i]]++;
    }
    cout << ans;
}

