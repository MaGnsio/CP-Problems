//https://codeforces.com/contest/1497/problem/C1
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
        int n, k;
        cin >> n >> k;
        if (n & 1) cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
        else if (n % 4) cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << "\n";
        else cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
    }
}

