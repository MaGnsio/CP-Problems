//https://codeforces.com/contest/51/problem/A
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
    int n, cnt = 0;
    unordered_map<string, int> m;
    cin >> n;
    while (n--)
    {
        string s, ss, te;
        cin >> s >> ss;
        if (n) cin >> te;
        string a = {s[0], s[1], ss[0], ss[1]};
        if (m[a]) continue;
        cnt++;
        string b = {ss[0], s[0], ss[1], s[1]};
        string c = {ss[1], ss[0], s[1], s[0]};
        string d = {s[1], ss[1], s[0], ss[0]};
        m[a]++, m[b]++, m[c]++, m[d]++;
    }
    cout << cnt;
}

