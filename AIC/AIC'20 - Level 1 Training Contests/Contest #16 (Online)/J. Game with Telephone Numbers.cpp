//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/J
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
    string s;
    cin >> n >> s;
    int k = n - 11, cnt = 0;
    for (int i = 0; i <= k; ++i) if (s[i] == '8') cnt++;
    cout << (cnt > k / 2 ? "YES" : "NO");
}

