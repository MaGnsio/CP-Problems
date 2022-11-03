//https://atcoder.jp/contests/abc196/tasks/abc196_c
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
    ll n, d = 0, cnt = 0, p = 1;
    cin >> n;
    for (ll i = 1; ; ++i) if (stoll (to_string (i) + to_string (i)) > n) return cout << i - 1, 0;
}

