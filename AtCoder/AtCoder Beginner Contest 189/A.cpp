//https://atcoder.jp/contests/abc189/tasks/abc189_a
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "Won";
    else cout << "Lost";
}

