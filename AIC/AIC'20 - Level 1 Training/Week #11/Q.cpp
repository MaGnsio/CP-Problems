//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/Q
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
    ll n, m, d;
    set<pair<ll, ll>> s;
    cin >> n >> m >> d;
    ll a[n], ans[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert ({a[i], i + 1});
    }
    ll cnt = 0;
    while (!s.empty ())
    {
        cnt++;
        ll pos = s.begin () -> S;
        ans[pos - 1] = cnt;
        s.erase (s.begin ());
        while (true)
        {
            auto it = s.lower_bound ({a[pos - 1] + d + 1, 0});
            if (it == s.end()) break;
            pos = it -> S;
            s.erase (it);
            ans[pos - 1] = cnt;
        }
    }
    cout << cnt << "\n";
    for (ll i = 0; i < n; i++) cout << ans[i] << " ";
}

