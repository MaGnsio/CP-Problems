//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/F
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
    int a[n], b[n];
    for (auto& x : a) cin >> x;
    if (n <= 2) return cout << 0, 0;
    int ans = INT_MAX;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int temp = abs(i) + abs(j);
            b[0] = a[0] + i, b[1] = a[1] + j;
            int diff = b[1] - b[0];
            bool valid = 1;
            for (int k = 2; k < n; ++k)
            {
                if (abs (b[k - 1] + diff - a[k]) <= 1)
                {
                    temp += abs (b[k - 1] + diff - a[k]);
                    b[k] = b[k - 1] + diff;
                }
                else valid = 0;
            }
            if (valid) ans = min (ans, temp);
        }
    }
  cout << (ans == INT_MAX ? -1 : ans);
}

