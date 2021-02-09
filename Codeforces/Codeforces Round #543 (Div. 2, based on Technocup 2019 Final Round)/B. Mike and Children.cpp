//https://codeforces.com/contest/1121/problem/B
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
    ll a[n], f[200005] = {};
    for (auto& X : a) cin >> X;
    for (ll i = 0; i < n - 1; ++i)
    {
        for (ll j = i + 1; j < n; ++j) f[a[i] + a[j]]++;
    }
    cout << *max_element (f, f + 200005);
}

