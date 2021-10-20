//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edf/00000000000510ed
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve (ll c)
{
    ll n;
    cin >> n;
    string x = to_string (n), y = x;
    for (ll i = 0; i < x.size (); ++i)
    {
        if ((x[i] - '0') & 1)
        {
            ll chk = (x[i] == '9' ? 10 : 0);
            x = x.substr (0, i) + to_string (x[i] - '0' + 1 + chk) + x.substr (i + 1);
            y = y.substr (0, i) + to_string (y[i] - '0' - 1) + y.substr (i + 1);
            for (ll j = i + 1; j < x.size (); ++j) x[j] = '0';
            for (ll j = i + 1; j < y.size (); ++j) y[j] = '8';
            break;
        }
    }
    ll a = stoll (x), b = stoll (y);
    cout << "Case #" << c << ": " << min (a - n, n - b) << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, c = 0;
    cin >> t;
    while (t--)
        solve (++c);
}

