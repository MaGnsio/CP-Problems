//https://vjudge.net/contest/414669#problem/I
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
        ll ans = LLONG_MAX;
        string s;
        cin >> s;
        vector<ll> freq(26);
        for (auto& elem : s) freq[elem - 'a']++;
        sort (freq.begin (), freq.end (), greater<ll> ());
        for (ll i = 1; i <= 26; ++i)
        {
            if (s.size () % i) continue;
            ll temb = 0;
            for (ll j = 0; j < i; ++j) temb += max (0ll, (s.size () / i) - freq[j]);
            ans = min (ans, temb);
        }
        cout << ans << "\n";
    }
}

