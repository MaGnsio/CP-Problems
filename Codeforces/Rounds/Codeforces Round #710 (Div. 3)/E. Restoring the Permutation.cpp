//https://codeforces.com/contest/1506/problem/E
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
    vector<ll> v(n);
    for (auto& x : v) cin >> x;
    //minimum permutation
    ll cnt = 1, currmax = 0;
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i)
    {
        if (v[i] != currmax)
        {
            cout << v[i] << " ";
            currmax = v[i];
            m[v[i]] = 1;
            continue;
        }
        while (m[cnt]) cnt++;
        cout << cnt << " ";
        m[cnt] = 1;
    }
    cout << "\n";
    //maxpermutation
    cnt = n, currmax = 0;
    m.clear ();
    for (ll i = 0; i < n; ++i)
    {
        if (v[i] != currmax)
        {
            cout << v[i] << " ";
            currmax = v[i];
            m[v[i]] = 1;
            cnt = v[i] - 1;
            continue;
        }
        while (m[cnt]) cnt--;
        cout << cnt << " ";
        m[cnt] = 1;
    }
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

