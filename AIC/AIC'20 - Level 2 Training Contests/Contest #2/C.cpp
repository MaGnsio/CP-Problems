//https://vjudge.net/contest/415649#problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll n, m, k;
const ll sz = 1000010;
ll a[sz], ctr[sz];

void init ()
{
    a[1] = 1, a[2] = 2, a[3] = 3;
    for (ll i = 4; i <= n; ++i) a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
    memset (ctr, 0, sz);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, cas = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        init ();
        ll c = 0, ans = LLONG_MAX;
        queue<ll> q;
        for (ll i = 1; i <= n; ++i)
        {
            if (a[i] <= k)
            {
                q.push (i);
                if (ctr[a[i]]++ == 0) c++;
            }
            while (c == k)
            {
                ans = min (ans, i - q.front () + 1);
                if (!--ctr[a[q.front ()]]) c--;
                q.pop ();
            }
        }
        if (ans == LLONG_MAX) cout << "Case " << cas++ << ": sequence nai\n";
        else cout << "Case " << cas++ << ": " << ans << "\n";
    }
}

