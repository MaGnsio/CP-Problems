//https://codeforces.com/group/Rv2Qzg0DgK/contest/272489/problem/G
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
    ll n, a, ans = 0;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> m;
    for (auto& elem : v)
    {
        cin >> elem;
        m[elem]++;
    }
    a = *max_element (v.begin (), v.end ()) + *min_element (v.begin (), v.end ());
    for (ll i = 0; i < a / 2 + (a & 1); ++i)
    {
        if (m.find (i) != m.end () && m.find (a - i) != m.end ()) ans += m[i] * m[a - i];
        if (ans == n / 2) break;
    }
    cout << ans + (a & 1 ? 0 : (m[a / 2] * (m[a / 2] - 1) / 2));
}

