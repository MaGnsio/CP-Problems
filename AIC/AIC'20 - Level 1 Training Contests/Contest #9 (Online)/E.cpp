//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/E
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
    ll a, b, s;
    cin >> a >> b >> s;
    cout << (abs (a) + abs (b) <= s && (s - abs (a) - abs (b)) % 2 == 0 ? "Yes" : "No");
}

