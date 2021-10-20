//https://vjudge.net/contest/420442#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, l, p, s = 0;
    cin >> n;
    priority_queue<ll> q;
    pair<ll, ll> a[n];
    for (auto& X : a) cin >> X.F >> X.S;
    cin >> l >> p;
    for (auto& X : a) X.F = l - X.F;
    sort (a, a + n);
    for (ll i = 0, j = 0; i < n; ++i)
    {
        if (a[i].F < 0) continue;
        if (a[i].F == 0)
        {
            p += a[i].S;
            continue;
        }
        ll d = a[i].F - (j ? a[i - 1].F : 0);
        p -= d, l -= d;
        while (p < 0 && !q.empty ())
        {
            ll temp = q.top ();
            q.pop ();
            p += temp;
            s++;
        }
        if (p < 0)
        {
            cout << -1 << "\n";
            return;
        }
        q.push (a[i].S);
        if (!l) break;
        j++;
    }
    if (l != 0)
    {
        p -= l, l = 0;
        while (p < 0 && !q.empty ())
        {
            ll temp = q.top ();
            q.pop ();
            p += temp;
            s++;
        }
    }
    if (p < 0)
    {
        cout << -1 << "\n";
        return;
    }
    cout << s << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

