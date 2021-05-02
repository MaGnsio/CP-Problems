//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/X
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll max_cost (ll n, vector<ll> v)
{
    ll cost = 0;
    sort (v.begin (), v.end (), greater<ll> ());
    while (n--)
    {
        cost += v[0];
        v[0]--;
        for (int i = 1; i < v.size (); ++i)
        {
            if (v[i] <= v[i - 1]) break;
            swap (v[i], v[i - 1]);
        }
    }
    return cost;
}
ll min_cost (ll n, vector<ll> v)
{
    ll cost = 0, i = 0;
    sort (v.begin (), v.end ());
    while (n--)
    {
        cost += v[i];
        v[i]--;
        if (!v[i]) i++;
    }
    return cost;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for (auto& x : v) cin >> x;
    cout << max_cost (n, v) << " " << min_cost (n, v);
}

