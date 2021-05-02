//https://codeforces.com/contest/1487/problem/A
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, i = 0;
        cin >> n;
        int a[n];
        for (auto& x : a) cin >> x;
        sort (a, a + n);
        for (; i < n; ++i) if (a[i] != a[0]) break;
        cout << n - i << "\n";
    }
}

