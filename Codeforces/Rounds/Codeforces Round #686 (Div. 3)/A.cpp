//https://codeforces.com/contest/1454/problem/A
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 2; i <= n; ++i) cout << i << " ";
        cout << 1 << "\n";
    }
}

