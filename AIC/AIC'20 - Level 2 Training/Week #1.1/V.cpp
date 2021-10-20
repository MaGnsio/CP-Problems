//https://vjudge.net/contest/416230#problem/V
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

string multiply (string a, string b)
{
    vector<ll> sum (a.size () + b.size (), 0);
    ll ai = 0, bi = 0;
    for (ll i = a.size () - 1; i >= 0; --i)
    {
        ll n1 = a[i] - '0', carry = 0;
        bi = 0;
        for (ll j = b.size () - 1; j >= 0; --j)
        {
            ll n2 = b[j] - '0';
            ll temb = n1 * n2 + sum[ai + bi] + carry;
            carry = temb / 10;
            sum[ai + bi] = temb % 10;
            bi++;
        }
        if (carry > 0) sum[ai + bi] += carry;
        ai++;
    }
    while (sum.back () == 0 && sum.size () > 1) sum.pop_back ();
    string ans = "";
    for (ll i = sum.size () - 1; i >= 0; --i) ans += to_string (sum[i]);
    return ans;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        cout << multiply (x, y) << "\n";
    }
}

