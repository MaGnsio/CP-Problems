//https://vjudge.net/contest/419722#problem/Z
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
    ll n, cnt = 1;
    cin >> n;
    vector<pair<bool, ll>> a(n + 1, {true, 0});
    for (ll i = 2; i <= n; ++i)
    {
        if (a[i].F)
        {
            a[i].S = cnt;
            for (ll j = 2 * i; j <= n; j += i) a[j].F = false, a[j].S = cnt;
            cnt++;
        }
    }
    for (ll i = 2; i <= n; ++i) cout << a[i].S << " ";
}

