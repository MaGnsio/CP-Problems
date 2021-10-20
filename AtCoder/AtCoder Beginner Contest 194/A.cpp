//https://atcoder.jp/contests/abc194/tasks/abc194_a
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
    int a, b;
    cin >> a >> b;
    if (a + b >= 15 && b >= 8) cout << 1;
    else if (a + b >= 10 && b >= 3) cout << 2;
    else if (a + b >= 3) cout << 3;
    else cout << 4;
}

