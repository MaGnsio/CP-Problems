//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/H
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
    ll n, sum = 0, chk = 0;
    cin >> n;
    ll a[n];
    for (auto& X : a) cin >> X;
    for (ll i = 0; i < n - 1; ++i) if (a[i] < 0) a[i] *= -1, a[i + 1] *= -1;
    for (auto& X : a) sum += X;
    if (a[n - 1] < 0)
    {
        a[n - 1] *= -1;
        sum += a[n - 1] * 2;
        sum -= *min_element (a, a + n) * 2;
    }
    cout << sum;
}

