//https://atcoder.jp/contests/abc188/tasks/abc188_b
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
    ll n, sum = 0;
    cin >> n;
    ll a[n], b[n];
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (ll i = 0; i < n; ++i) sum += (a[i] * b[i]);
    cout << (sum ? "No" : "Yes");
}

