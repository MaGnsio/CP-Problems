//https://codeforces.com/contest/1506/problem/B
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
        int i, j, cnt = 0;
        for (i = 0; i < n; ++i) if (s[i] == '*')
        {
            s[i] = 'x';
            cnt++;
            break;
        }
        for (j = n - 1; j > i; --j) if (s[j] == '*')
        {
            s[j] = 'x';
            cnt++;
            break;
        }
        if (cnt < 2)
        {
            cout << cnt << "\n";
            continue;
        }
        while (j - i > k)
        {
            for (int x = i + k; x > i; --x) if (s[x] == '*')
            {
                s[x] = 'x';
                cnt++;
                i = x;
                break;
            }
        }
        cout << cnt << "\n";
    }
}

