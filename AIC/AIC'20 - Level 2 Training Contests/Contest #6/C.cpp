//https://vjudge.net/contest/420442#problem/C
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
    ll n, res = 1;
    cin >> n;
    if (n < 3) return cout << -1, 0;
    if (n == 3) return cout << 210, 0;
    for (ll i = 1; i < n; ++i) res = (res * 10) % 210;
    res = 210 - res;
    string s = to_string (res), r = "1";
    while (r.size () + s.size () < n) r.push_back ('0');
    cout << r << s;
}

