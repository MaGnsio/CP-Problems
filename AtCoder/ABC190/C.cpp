//https://atcoder.jp/contests/abc190/tasks/abc190_c
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
    int n, m, k, ans = 0;
    cin >> n >> m;
    pair<int, int> a[m];
    for (auto& x : a)
    {
        cin >> x.F >> x.S;
    }
    cin >> k;
    pair<int, int> b[k];
    for (auto& x : b) cin >> x.F >> x.S;
    for (int i = 0; i < (1 << k); ++i)
    {
        vector<bool> c (n, false);
        for (int j = 0; j < k; ++j)
        {
            int x = b[j].F - 1, y = b[j].S - 1;
            c[i & (1 << j) ? x : y] = 1; // (...0001, ...0010, ...0011, ...0100, ..., 2^k) X (...0001, ...0010, ...0100, ...1000, ..., 2^k)
        }
        int cnt = 0;
        for (auto& x : a)
        {
            if (c[x.F - 1] && c[x.S - 1]) cnt++;
        }
        ans = max (ans, cnt);
    }
    cout << ans;
}

