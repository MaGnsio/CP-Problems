//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/M
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
    ll n, k, curr = 1, cnt = 0;
    cin >> n >> k;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (int l = 0, r = 0; r < n; ++r)
    {
        curr *= a[r];
        while (l < r && curr >= k) curr /= a[l++];
        if (curr < k) cnt += (r - l + 1);

    }
    cout << cnt;
}

