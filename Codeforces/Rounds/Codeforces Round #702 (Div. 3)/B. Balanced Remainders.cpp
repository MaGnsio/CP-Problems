//https://codeforces.com/contest/1490/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n, x = 0, y = 0, z = 0, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;
        x += (j % 3 == 0), y += (j % 3 == 1), z += (j % 3 == 2);
    }
    while (x < n / 3)
    {
        if (z > n / 3)
        {
            int d = min (z - n / 3, n / 3 - x);
            cnt += d, x += d, z -= d;
        }
        else
        {
            int d = min (y - n / 3, n / 3 - x);
            cnt += 2 * d, x += d, y -= d;
        }
    }
    while (y < n / 3)
    {
        if (x > n / 3)
        {
            int d = min (x - n / 3, n / 3 - y);
            cnt += d, y += d, x -= d;
        }
        else
        {
            int d = min (z - n / 3, n / 3 - y);
            cnt += 2 * d, y += d, z -= d;
        }
    }
    while (z < n / 3)
    {
        if (y > n / 3)
        {
            int d = min (y - n / 3, n / 3 - z);
            cnt += d, z += d, y -= d;
        }
        else
        {
            int d = min (x - n / 3, n / 3 - z);
            cnt += 2 * d, z += d, x -= d;
        }
    }
    cout << cnt << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

