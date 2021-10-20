//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/T
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, i = 0, maxa = 0, tp;
    cin >> n;
    vector<ll> v(n);
    stack<ll> s;
    for (auto& elem : v) cin >> elem;
    while (i < n)
    {
        if (s.empty () || v[s.top ()] <= v[i]) s.push (i++);
        else
        {
            tp = s.top ();
            s.pop ();
            //we calculate the area from 's.top()' to 'i' when v[tp] is the smallest bar in the rectangle
            maxa = max (maxa, v[tp] * (s.empty () ? i : i - s.top () - 1));
        }
    }
    while (!s.empty ())
    {
            tp = s.top ();
            s.pop ();
            maxa = max (maxa, v[tp] * (s.empty () ? n : n - s.top () - 1));
    }
    cout << maxa << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve ();
    }
}

