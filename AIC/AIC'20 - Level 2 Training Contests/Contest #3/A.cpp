//https://vjudge.net/contest/416541#problem/A
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
    ll n, ctr = 1;
    cin >> n;
    vector<ll> v(n), a(n), b(n), ans;
    for (ll i = 0; i < n; ++i) v[i] = i + 1;
    for (auto& elem : a) cin >> elem;
    for (auto& elem : b) cin >> elem;
    do
    {
        ll chk1 = 1, chk2 = 1;
        for (ll i = 0; i < n; ++i)
        {
            if (v[i] == a[i]) continue;
            chk1 = 0;
        }
        for (ll i = 0; i < n; ++i)
        {
            if (v[i] == b[i]) continue;
            chk2 = 0;
        }
        if (chk1) ans.push_back (ctr);
        if (chk2) ans.push_back (ctr);
        if (ans.size () == 2) break;
        ctr++;
    } while (next_permutation (v.begin (), v.end ()));
    cout << abs (ans[0] - ans[1]);
}

