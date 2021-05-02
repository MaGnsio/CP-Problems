//https://codeforces.com/contest/1511/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
            cnt += (x != 2);
        }
        cout << cnt << "\n";
    }
}

