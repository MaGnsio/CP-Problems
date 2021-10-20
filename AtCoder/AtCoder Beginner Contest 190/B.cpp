//https://atcoder.jp/contests/abc190/tasks/abc190_b
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
    int n, s, d;
    cin >> n >> s >> d;
    int chk = 0;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        if (x < s && y > d) chk = 1;
    }
    cout << (chk ? "Yes" : "No");
}

