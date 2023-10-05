//https://codeforces.com/contest/1497/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n;
    cin >> n;
    int f[101] = {};
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        f[x]++;
    }
    bool chk = true;
    while (chk)
    {
        chk = false;
        for (int i = 0; i < 101; ++i)
        {
            if (f[i])
            {
                cout << i << " ";
                f[i]--;
                chk = true;
            }
        }
    }
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

