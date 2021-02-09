//https://vjudge.net/contest/416230#problem/U
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

string add (string a, string b)
{
    string sum = "";
    if (a.size () > b.size ()) swap (a, b);
    reverse (a.begin (), a.end ());
    reverse (b.begin (), b.end ());
    ll carry = 0;
    for (ll i = 0; i < a.size (); ++i)
    {
        ll temb = (a[i] - '0') + (b[i] - '0') + carry;
        sum.push_back (temb % 10 + '0');
        carry = temb / 10;
    }
    for (ll i = a.size (); i < b.size (); ++i)
    {
        ll temb = (b[i] - '0') + carry;
        sum.push_back (temb % 10 + '0');
        carry = temb / 10;
    }
    if (carry) sum.push_back (carry + '0');
    reverse (sum.begin (), sum.end ());
    return sum;
}
string substract (string a, string b)
{
    bool sign = 1;
    string sum = "";
    if ((a.size () < b.size ()) || (a.size () == b.size () && lexicographical_compare (a.begin (), a.end (), b.begin (), b.end ())))
    {
            swap (a, b);
            sign = 0;
    }
    reverse (a.begin (), a.end ());
    reverse (b.begin (), b.end ());
    ll carry = 0;
    for (ll i = 0; i < b.size (); ++i)
    {
        ll temb = (a[i] - '0') - (b[i] - '0') - carry;
        if (temb < 0)
        {
            temb += 10;
            carry = 1;
        }
        else carry = 0;
        sum.push_back (temb + '0');
    }
    for (ll i = b.size (); i < a.size (); ++i)
    {
        ll temb = (a[i] - '0') - carry;
        if (temb < 0)
        {
            temb += 10;
            carry = 1;
        }
        else carry = 0;
        sum.push_back (temb + '0');
    }
    while (sum.back () == '0' && sum.size () > 1) sum.pop_back ();
    if (!sign) sum.push_back ('-');
    reverse (sum.begin (), sum.end ());
    return sum;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll q;
        string a, b;
        cin >> q >> a >> b;
        if (q == 1) cout << add (a, b) << "\n";
        else cout << substract (a, b) << "\n";
    }
}

