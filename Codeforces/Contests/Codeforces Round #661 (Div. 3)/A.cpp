//https://codeforces.com/problemset/problem/1399/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n);
    for (ll i = 1; i < n; ++i) if (a[i] - a[i - 1] > 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

