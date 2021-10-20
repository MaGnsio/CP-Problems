//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/G
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
    ll n, cnt1 = 0, cnt2 = 0;
    cin >> n;
    ll a[n];
    for (auto& X : a) cin >> X;
    for (ll i = 0; i < n; ++i) if (((i & 1) && a[i] < 0) || (!(i & 1) && a[i] > 0)) cnt1++;
    for (ll i = 0; i < n; ++i) if ((!(i & 1) && a[i] < 0) || ((i & 1) && a[i] > 0)) cnt2++;
    cout << min (cnt1, cnt2);
}

