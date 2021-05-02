//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/B
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
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size (); ++i) cout << (a[i] ^ b[i]);
}

