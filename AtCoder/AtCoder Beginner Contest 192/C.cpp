//https://atcoder.jp/contests/abc192/tasks/abc192_c
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll k;
    string n;
    cin >> n >> k;
    string x = n, y = n;
    sort (x.begin (), x.end ());
    sort (y.begin (), y.end (), greater<char> ());
    ll f = stoll (n);
    while (k--)
    {
        f = stoll (y) - stoll (x);
        x = to_string (f), y = x;
        sort (x.begin (), x.end ());
        sort (y.begin (), y.end (), greater<char> ());
    }
    cout << f;
}

