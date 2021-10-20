//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/S
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
    vector<ll> v(n);
    stack<ll> s;
    for (auto& elem : v)
    {
        cin >> elem;
        elem &= 1;
    }
    for (ll i = 0; i < n; ++i)
    {
        if (!s.empty () && s.top () == v[i]) s.pop ();
        else s.push (v[i]);
    }
    cout << (s.size () <= 1 ? "YES" : "NO");
}

