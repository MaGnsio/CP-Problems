//https://vjudge.net/contest/416254#problem/N
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

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
    ll n;
    cin >> n;
    for (ll i = 1; i < n; ++i)
    {
        for (ll j = 1; j < n; ++j) cout << from_decimal (i * j, n) << " ";
        cout << "\n";
    }
}

