//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/J
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& elem : a) cin >> elem;
    sort (a.begin (), a.end ());
    ll l = 0, r = n - 1, x = a[l] + a[r], ctr = 0;
    while (l < r)
    {
        if (a[l] + a[r] == x) ctr++, l++, r--;
        else if (a[l] + a[r] > x) r--;
        else l++;
    }
    cout << ctr;
}

