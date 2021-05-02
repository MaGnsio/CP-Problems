//https://atcoder.jp/contests/abc186/tasks/abc186_c
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e5 + 1;

vector<int> v(sz, 0);

void init ()
{
    function<bool(int)> f = [] (int n) -> bool
    {
        int x = n;
        while (x)
        {
            if (x % 10 == 7) return false;
            x /= 10;
        }
        x = n;
        while (x)
        {
            if (x % 8 == 7) return false;
            x /= 8;
        }
        return true;
    };
    for (int i = 0; i < sz; ++i) if (f (i)) v[i] = 1;
    for (int i = 1; i < sz; ++i) v[i] += v[i - 1];
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    int n;
    cin >> n;
    cout << v[n] - v[0];
}

