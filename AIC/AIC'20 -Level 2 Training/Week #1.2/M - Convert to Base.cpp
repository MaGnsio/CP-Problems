//https://vjudge.net/contest/416254#problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll decimal_digit (char c)
{
    if (c >= '0' && c <= '9') return (ll) (c - '0');
    else return (ll) (c - 'A' + 10);
}
ll to_decimal (string s, ll base)
{
    ll p = 1, v = 0;
    for (ll i = s.size () - 1; i >= 0; --i) v += decimal_digit (s[i]) * p, p *= base; 
    return v;
}
char ndecimal_digit (ll d)
{
    if (d >= 0 && d <= 9) return (char) (d + '0');
    else return (char) (d + 'A' - 10);
}
string from_decimal (ll v, ll base)
{
    string s;
    while (v > 0) s.push_back (ndecimal_digit (v % base)), v /= base;
    reverse (s.begin (), s.end ());
    return s;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    if (t == 1)
    {
        ll x;
        string s;
        cin >> s >> x;
        cout << to_decimal (s, x);
    }
    else
    {
        ll n, x;
        cin >> n >> x;
        cout << from_decimal (n, x);
    } 
}

