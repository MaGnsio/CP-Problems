//https://codeforces.com/contest/1486/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, sum = 0, chk = 1;
        cin >> n;
        for (ll i = 0; i < n; ++i)
        {
            ll x;
            cin >> x;
            sum += x;
            if (sum < i * (i + 1) / 2) chk = 0;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

