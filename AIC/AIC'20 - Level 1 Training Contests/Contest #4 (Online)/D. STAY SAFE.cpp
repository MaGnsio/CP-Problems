//https://codeforces.com/group/aDFQm4ed6d/contest/273591/problem/D
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
    ll n, ans = 0, pow = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ans += pow;
        pow *= 2;
    }
    cout << ans;
}

