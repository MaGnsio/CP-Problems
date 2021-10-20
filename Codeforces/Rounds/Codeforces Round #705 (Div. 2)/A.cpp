//https://codeforces.com/contest/1493/problem/A
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
        vector<int> v;
        cin >> n >> k;
        for (int i = k - 1; i >= (k + 1) / 2; --i) v.push_back (i);
        for (int i = k + 1; i <= n; ++i) v.push_back (i);
        if (v.empty ()) cout << 0 << "\n";
        else
        {
            cout << v.size () << "\n";
            for (auto& x : v) cout << x << " ";
            cout << "\n";
        }
    }
}

