//https://codeforces.com/group/Rv2Qzg0DgK/contest/286457/problem/U
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int sp (int num) 
{ 
    int cnt = 0; 
    for (int i = 2; cnt < 2 && i * i <= num; ++i)
    {
        while (num % i == 0)
        {
            if (num > 1) num /= i, cnt++;
        }
    }
    if (num > 1) cnt++;
    return cnt == 2; 
} 
  
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    //preprocessing
    const int sz = 2'000'001;
    int dp[2'000'001] = {};
    bitset<sz> b;
    b.set ();
    b[0] = b[1] = false;
    for (int i = 2; i * i <= sz; ++i)
    {
        if (b[i])
        {
            for (int j = i * i; j <= sz; j += i) b[j] = false;
        }
    }
    for (int i = 0; i < sz; ++i)
    {
        if (b[i]) continue;
        dp[i] = sp (i);
    }
    for (int i = 1; i < sz; ++i) dp[i] += dp[i - 1];
    //actual problem
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << dp[r] - (l ? dp[l - 1] : 0) << "\n";
    }
}

