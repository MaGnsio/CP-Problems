//https://atcoder.jp/contests/abc185/tasks/abc185_a
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
    ll A1, A2, A3, A4;
    cin >> A1 >> A2 >> A3 >> A4;
    cout << min ({A1, A2, A3, A4});
}

