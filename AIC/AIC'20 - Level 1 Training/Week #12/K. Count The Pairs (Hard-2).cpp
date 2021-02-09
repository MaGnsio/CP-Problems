//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/K
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
    vector<ll> a(n);
    map<ll, ll> m;
    for (auto& elem : a)
    {
        cin >> elem;
        m[elem]++;
    }

    vector<ll> v(a);
    sort (v.begin (), v.end ());
    auto it = unique (v.begin (), v.end ());
    v.resize (distance (v.begin (), it));

    ll l = 0, r = v.size () - 1, x = v[l] + v[r], ctr = 0;
    while (l < r)
    {
        if (v[l] + v[r] == x)
        {
            ctr += m[v[l++]] * m[v[r--]];
            continue;
        }
        if (v[l] + v[r] > x) r--;
        else l++;
    }
    cout << ctr + (x & 1 ? 0 : m[x / 2] * (m[x / 2] - 1) / 2);
}

