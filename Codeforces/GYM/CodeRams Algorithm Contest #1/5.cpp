//https://codeforces.com/gym/102892/problem/5
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1001;

ll n, m, k;
vector<ll> v (sz);
vector<string> t (sz);

bool chk (ll mid)
{
    ll curs = 0;
    for (ll i = 0; i < m; ++i)
    {
        ll cnt = 0;
        priority_queue<ll> q;
        for (ll j = 0; j < n; ++j)
        {
            if (t[j][i] == '1') q.push (v[j]);
        }
        while (!q.empty () && cnt < mid)
        {
            curs += q.top ();
            q.pop ();
            cnt++;
        }
    }
    return curs >= k;
}


int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> m >> k;
    for (ll i = 0; i < n; ++i) cin >> v[i];
    for (ll i = 0; i < n; ++i) cin >> t[i];
    ll l = 1, r = n, ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (chk (mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
}

