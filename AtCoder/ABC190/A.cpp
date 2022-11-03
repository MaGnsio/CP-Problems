//https://atcoder.jp/contests/abc190/tasks/abc190_a
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
    int a, b, c;
    cin >> a >> b >> c;
    if (!c)
        if (a > b) cout << "Takahashi";
        else cout << "Aoki";
    else
        if (a >= b) cout << "Takahashi";
        else cout << "Aoki";
}

