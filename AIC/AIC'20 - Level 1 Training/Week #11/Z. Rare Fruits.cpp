//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/Z
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
    int n, m, response, ans = -1;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int l = 0, r = m - 1, temp = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            cout << 1 << " " << i << " " << mid << endl;
            cin >> response;
            if (response) r = mid - 1, temp = mid;
            else l = mid + 1;
        }
        if (ans != -1 && temp != -1) ans = min (ans, temp);
        else if (temp != -1) ans = temp;
    }
    cout << 2 << " " << ans << endl;
}
