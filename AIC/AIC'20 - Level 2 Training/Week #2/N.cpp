//https://vjudge.net/contest/417978#problem/N
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
    stack<ll> q;
    cin >> n >> k >> s;
    bool chk[n] = {};
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == '(') q.push (i);
        if (s[i] == ')' && !q.empty ()) chk[q.top ()] = true, chk[i] = true, k -= 2, q.pop ();
        if (!k) break;
    }
    for (ll i = 0; i < n; ++i) if (chk[i]) cout << s[i];
}

