//https://atcoder.jp/contests/abc196/tasks/abc196_b
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
    string n;
    cin >> n;
    for (auto& x : n)
    {
        if (x == '.') break;
        cout << x;
    }
}

