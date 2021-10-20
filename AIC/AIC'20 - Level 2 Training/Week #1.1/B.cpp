//https://vjudge.net/contest/416230#problem/B
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
    ll n, ans = 0;
    ll a[5] = {};
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s[0] == 'M') a[0]++;
        if (s[0] == 'A') a[1]++;
        if (s[0] == 'R') a[2]++;
        if (s[0] == 'C') a[3]++;
        if (s[0] == 'H') a[4]++;
    }
    for (ll i = 0; i < 5; ++i)
    {
        for (ll j = i + 1; j < 5; ++j)
        {
            for (ll k = j + 1; k < 5; ++k) ans += a[i] * a[j] * a[k];
        }
    }
    cout << ans;
}

