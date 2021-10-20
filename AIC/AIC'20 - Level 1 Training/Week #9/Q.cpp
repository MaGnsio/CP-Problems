//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/Q
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
    stack<ll> s;
    cin >> n;
    vector<ll> v1(n), v2;
    for (auto& elem : v1) cin >> elem;
    for (ll i = n - 1; i >= 0; --i)
    {
        while (!s.empty () && s.top () <= v1[i]) s.pop ();
        if (s.empty ()) v2.push_back (-1);
        else v2.push_back (s.top ());
        s.push (v1[i]);
    }
    reverse (v2.begin (), v2.end ());
    for (auto& elem : v2) cout << elem << " ";
}

