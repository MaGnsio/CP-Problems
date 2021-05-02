//https://atcoder.jp/contests/abc192/tasks/abc192_d
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool chk (string s, ll mid, ll m)
{
    ll base = 1, sum = 0;
    for (ll i = s.size () - 1; i >= 0; --i)
    {
        ll digit = s[i] - '0';
        if ((m - sum + base - 1) / base < digit) return 0;
        sum += base * digit;
        if (sum > m) return 0;
        if (i > 0)
        {
            if ((m + base - 1) / base < mid) return 0;
            base *= mid;
        }
    }
    return 1;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll m;
    string x;
    cin >> x >> m;
    ll d = *max_element (x.begin (), x.end ()) - '0';
    ll l = d + 1, r = 2e18, b = d;
    if (x.size () == 1)
    {
        if (d <= m) return cout << 1, 0;
        else return cout << 0, 0;
    }
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (chk (x, mid, m)) l = mid + 1, b = mid;
        else r = mid - 1;
    }
    cout << b - d;
}

