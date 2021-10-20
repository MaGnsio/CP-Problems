//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/I
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
    ll cal = 0;
    ll a[4];
    string s;
    for (auto& x : a) cin >> x;
    cin >> s;
    for (auto& x : s) cal += a[x - '0' - 1];
    cout << cal;
}

