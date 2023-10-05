//https://codeforces.com/contest/1513/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        iota (v.begin (), v.end (), 1);
        if (k > (n - 1) / 2) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 1; i < n && k > 0; i += 2, k--) {
                swap (v[i], v[i + 1]);
        }
        for (auto& x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

