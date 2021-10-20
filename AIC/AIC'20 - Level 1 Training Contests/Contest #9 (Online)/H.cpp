//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/H
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
    ll n, s, e, cnt = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            cnt++;
            s = i + 1;
            while (a[i] > a[i + 1] && i < n - 1) i++;
            e = i + 1;
        }
        if (cnt > 1) return cout << "no", 0;
    }
    if (cnt == 0) return cout << "yes\n1 1", 0;
    reverse (a + s - 1, a + e);
    for (ll i = 0; i < n - 1; ++i) if (a[i] > a[i + 1]) return cout << "no", 0;
    cout << "yes\n" << s << " " << e;
}

