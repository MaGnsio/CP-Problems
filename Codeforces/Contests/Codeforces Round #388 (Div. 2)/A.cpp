//https://codeforces.com/problemset/problem/749/A
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
    ll n;
    cin >> n;
    cout << (n / 2) << "\n";
    for (ll i = 1; i < n / 2; ++i) cout << 2 << " ";
    cout << (n & 1 ? 3 : 2);
}

