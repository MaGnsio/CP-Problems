//https://vjudge.net/contest/416254#problem/R
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
    ll n, cnt = 0;
    cin >> n;
    ll a[n], b[n];
    unordered_set<ll> s;
    for (auto& elem : a)
    {
        cin >> elem;
        s.insert (elem);
    }
    for (auto& elem : b)
    {
        cin >> elem;
        s.insert (elem);
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < n; ++j)
        {
            if (s.count (a[i] ^ b[j]) == 1) cnt++;
        }
    }
    if (cnt & 1) cout << "Koyomi";
    else cout << "Karen";
}

