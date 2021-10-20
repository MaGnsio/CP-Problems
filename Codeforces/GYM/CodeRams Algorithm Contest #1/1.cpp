//https://codeforces.com/gym/102892/problem/1
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
    int n, cnt = 0;
    map<int, int> m;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto& x : m) if (x.S == 1) cnt++;
    cout << cnt;
}

