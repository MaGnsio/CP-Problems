//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/B
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
    char s;
    int h[2], m[2];
    for(int i = 0; i < 2; i++) cin >> h[i] >> s >> m[i];
    h[0] -= h[1];
    m[0] -= m[1];
    if (m[0] < 0) m[0] += 60, h[0]--;
    if (h[0] < 0) h[0] += 24;
    if (h[0] < 10) cout << 0;
    cout << h[0] << ":";
    if (m[0] < 10) cout << 0;
    cout << m[0];
}

