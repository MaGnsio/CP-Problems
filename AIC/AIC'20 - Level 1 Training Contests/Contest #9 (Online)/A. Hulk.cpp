//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/A
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
    int n;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        if (i & 1) cout << "I hate ";
        else cout << "I love ";
        if (i < n) cout << "that ";
    }
    cout << "it";
}

