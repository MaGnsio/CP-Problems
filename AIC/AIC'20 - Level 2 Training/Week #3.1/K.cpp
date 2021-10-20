//https://vjudge.net/contest/419722#problem/K
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
    ll c[256] = {}, f[1001];
    memset (f, 1, sizeof(f));
    string s;
    cin >> s;
    ll n = s.size (), k = 0;
    for (ll i = 0; i < n; ++i) c[s[i]]++;
    for (ll i = 0; i < 256; i++) if (c[i] > c[k]) k = i;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (f[i])
        {
            for (ll j = i * i; j <= n; j += i) f[j] = 0;
        }
    }
    for (ll i = 2; i + i <= n; ++i) f[i] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (!f[i])
        {
            if (c[k] == 0) return cout << "NO", 0;
            c[s[i - 1] = k]--;
        }
    }
    k = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (f[i])
        {
            while (c[k] == 0) k++;
            c[s[i - 1] = k]--;
        }
    }
    cout << "YES\n" << s;
}

