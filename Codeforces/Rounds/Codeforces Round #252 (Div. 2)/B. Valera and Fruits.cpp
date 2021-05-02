//https://codeforces.com/contest/441/problem/B
#include <bits/stdc++.h>
using namespace std;
const int sz = 3500;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, v;
    cin >> n >> v;
    vector<pair<int, int>> d(sz, {0, 0});
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        d[x].first += y, d[x + 1].second += y;
    }
    int cnt = 0;
    for (int i = 1; i < sz - 1; ++i)
    {
        int x = min (d[i].second, v);
        d[i].second -= x;
        cnt += x;
        if (x < v)
        {
            int y = min (v - x, d[i].first);
            d[i].first -= y;
            d[i + 1].second -= y;
            cnt += y;
        }
    }
    cout << cnt;
}

