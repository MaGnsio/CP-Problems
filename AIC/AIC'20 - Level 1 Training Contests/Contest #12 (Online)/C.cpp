//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/C
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
    int n, t = INT_MAX;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        for (int j = 0; j < a[i]; ++j)
        {
            int x;
            cin >> x;
            temp += (x * 5) + 15;
        }
        t = min (temp, t);
    }
    cout << t;
}

