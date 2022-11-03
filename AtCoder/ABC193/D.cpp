//https://atcoder.jp/contests/abc193/tasks/abc193_d
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll k, a = 0, b = 0, w = 0, all = 0, sum = 0;
    string s, t;
    cin >> k >> s >> t;
    vector<ll> f(10, k), x(10, 0), y(10, 0), p(6, 1);
    for (ll i = 0; i < 4; ++i) x[s[i] - '0']++, y[t[i] - '0']++;
    for (ll i = 1; i < 10; ++i) f[i] -= (x[i] + y[i]);
    for (ll i = 0, j = 1; i < 6; ++i, j *= 10) p[i] = j;
    for (ll i = 1; i < 10; ++i) a += (i * p[x[i]]), b += (i * p[y[i]]), sum += f[i];
    for (ll i = 1; i < 10; ++i)
    {
        if (!f[i]) continue;
        for (ll j = 1; j < 10; ++j)
        {
            if (!f[j] || (i == j && f[i] < 2)) continue;
            ll temp1 = a - (i * p[x[i]]) + (i * p[x[i] + 1]);
            ll temp2 = b - (j * p[y[j]]) + (j * p[y[j] + 1]);
            if (temp1 > temp2) w += (f[i] * (i == j ? f[i] - 1 : f[j])) ;
            all += (f[i] * (i == j ? f[i] - 1 : f[j]));
        }
    }
    ld prb = (ld) w / (ld) all;
    cout << fixed << setprecision (20) << prb;
}

