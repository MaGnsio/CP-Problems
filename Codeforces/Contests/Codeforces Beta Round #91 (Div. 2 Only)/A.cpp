//https://codeforces.com/problemset/problem/122/A
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
    function<bool(int)> chk = [] (int n) -> bool {while (n) {if (n % 10 != 4 && n % 10 != 7) return false; n /= 10;} return true;};
    vector<int> dp;
    for (int i = 1; i <= 1000; ++i) if (chk (i)) dp.push_back (i);
    int n;
    cin >> n;
    for (int i = 0; i < dp.size (); ++i) if (n % dp[i] == 0) return cout << "YES", 0;
    cout << "NO";
}
