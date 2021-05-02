//
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
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> v (n);
    for (auto& x : v) cin >> x;
    // A"1", S"1" (0,1), ..., S"n - 1" (0,1), A"n" : S is the a place which the bar could be but on, so we have 2^(n - 1) probability to but the bars.
    for (int mask = 0; mask < (1 << (n - 1)); ++mask)
    {
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i)
        {
            x |= v[i];
            if (i == n - 1 || (mask >> i) & 1) y ^= x, x = 0; //we check for the Ith bit in the mask which represents the Ith bar status.
        }
        ans = min (ans, y);
    }
    cout << ans;
}

