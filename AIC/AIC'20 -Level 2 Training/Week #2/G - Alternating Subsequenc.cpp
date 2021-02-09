//https://vjudge.net/contest/417978#problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> v(n);
    for (auto& X : v) cin >> X;
    for (ll i = 0; i < n; ++i)
    {
        ll temp = v[i];
        if (v[i] < 0) while (v[i + 1] < 0 && i + 1 < n) temp = max (temp, v[i + 1]), i++;
        else while (v[i + 1] > 0 && i + 1 < n) temp = max (temp, v[i + 1]), i++;
        sum += temp;
    }
    cout << sum << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

