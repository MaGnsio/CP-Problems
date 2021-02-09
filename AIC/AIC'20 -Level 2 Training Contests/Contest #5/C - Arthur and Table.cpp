//https://vjudge.net/contest/418569#problem/C
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
    ll n, ans = LLONG_MAX;
    ll cnt[210] = {}; //number of legs that require (i) units of energy to remove it
    cin >> n;
    pair<ll, ll> leg[n + 1] = {};
    for (ll i = 1; i <= n; ++i) cin >> leg[i].F;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> leg[i].S;
        cnt[leg[i].S]++;
    }
    sort (leg + 1, leg + n + 1, greater<pair<ll, ll>> ());
    ll ra = 0;
    for (ll i = 1; i <= n; ++i)
    {
        while (leg[i].F == leg[i - 1].F && i <= n) ra += leg[i].S, ++i; //first we remove legs that are bigger than specified maximum leg hight (leg[j])
        ll j = i;
        while (leg[j].F == leg[j + 1].F && j <= n) cnt[leg[j].S]--, j++; //remove counter of leg[j] as we want to keep them
        if (j <= n) cnt[leg[j].S]--;
        ll rb = 0, d = max (0LL, n - (i - 1) - (j - i + 1) * 2 + 1), k = 1;
        while (d) //now we remove legs that require less energy untill we make the table stable
        {
            ll x = min (d, cnt[k]);
            d -= x, rb += x * k;
            k++;
        }
        ans = min (ans, ra + rb); //update answer
        if (i <= n && leg[i].F != leg[i - 1].F) ra += leg[i].S;
    }
    cout << ans;
}

