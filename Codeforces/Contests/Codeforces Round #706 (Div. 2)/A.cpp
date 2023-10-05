//https://codeforces.com/contest/1496/problem/A
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
        string s;
        cin >> n >> k >> s;
        if (k == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (2 * k == n)
        {
            cout << "NO\n";
            continue;
        }
        bool chk = true;
        for (int i = 0; i < k; ++i) if (s[i] != s[n - i - 1])
        {
            chk = false;
            break;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

