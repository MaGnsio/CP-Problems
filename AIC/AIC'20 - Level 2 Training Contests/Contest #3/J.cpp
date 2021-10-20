//https://vjudge.net/contest/416541#problem/J
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
    ll n;
    cin >> n;
    ll a[n];
    unordered_set<ll> s;
    for (auto& elem : a)
    {
        cin >> elem;
        s.insert (elem);
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            if (s.count (a[i] ^ a[j]) == 1) return cout << "YES", 0;
        }
    }
    cout << "NO";
}

