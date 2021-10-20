//https://codeforces.com/gym/102892/problem/3
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
    int n, lb = -1, chk = 0, cnt = 0;
    string s;
    cin >> n >> s;
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] == 'a') chk = 1;
        if (s[i] == 'b')
        {
            if (chk) cnt += i - lb - 1;
            chk = 0;
            lb = i;
        }
    }
    if (chk) cnt += n - lb - 1;
    cout << cnt;
}

