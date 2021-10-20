//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/B
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
    ll n, k;
    string s;
    ll dp[26] = {};
    set<char> _s;
    cin >> n >> k >> s;
    for (ll i = 0; i < k; ++i) _s.insert (s[i]), dp[s[i] - 'a']++;
    ll st = 0, en = k, ans = _s.size ();
    while (en < n)
    {
        if (dp [s[st] - 'a'] == 1) _s.erase (s[st]), dp[s[st++] - 'a']--;
        else dp[s[st++] - 'a']--;
        _s.insert (s[en]), dp [s[en++] - 'a']++;
        ans = max (ans, (ll)_s.size ());
    }
    cout << ans;
}

