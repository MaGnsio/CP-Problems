//https://atcoder.jp/contests/abc181/tasks/abc181_c
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
    vector<pair<int, int>> v (n);
    for (auto& x : v) cin >> x.F >> x.S;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if ((v[j].S - v[i].S) * (v[k].F - v[i].F) == (v[k].S - v[i].S) * (v[j].F - v[i].F))
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}

