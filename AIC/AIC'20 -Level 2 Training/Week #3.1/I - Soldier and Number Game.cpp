//https://vjudge.net/contest/419722#problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

vector<pair<bool,ll>> pfc (5'000'001, {true,0});
void init ()
{
    pfc[0].F = pfc[1].F = false;
    for (ll i = 2; i <= 5'000'000; ++i)
    {
        if (pfc[i].F)
        {
            pfc[i].S = 1;
            for (ll j = 2 * i; j <= 5'000'000; j += i)
            {
                pfc[j].F = false;
                ll temp = j;
                while (temp % i == 0) temp /= i, pfc[j].S++;
            }
        }
    }
    for (ll i = 1; i <= 5'000'000; ++i) pfc[i].S += pfc[i - 1].S;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << pfc[a].S - pfc[b].S << "\n";
    }
}

