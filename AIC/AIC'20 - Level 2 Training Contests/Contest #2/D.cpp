//https://vjudge.net/contest/415649#problem/D
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
    ll n, ans = 1;
    string s;
    cin >> n >> s;
    for (ll i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1]) continue;
        ans++;
    }
    cout << ans;
}

