//https://vjudge.net/contest/421809#problem/B
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll f[26] = {};
        string x, y;
        cin >> x >> y;
        for (auto& c : x) f[c - 'a']++;
        for (auto& c : y) f[c - 'a']++;
        ll cnt = x.size ();
        for (ll i = 0; i < 26 && cnt; ++i)
        {
            for (ll j = 0; j < f[i] && cnt; ++j, --cnt) cout << char ('a' + i);
        }
        cout << "\n";
    }
}

