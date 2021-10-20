//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/F
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
    ll n, m, x, ans = 0;
    map<ll, ll> a;
    cin >> n >> m;
    for (ll i = 0; i < m + n; ++i)
    {
        cin >> x;
        if (a[x]) ans++;
        a[x]++;
    }
    cout << ans;
}

