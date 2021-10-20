//https://vjudge.net/contest/433102#problem/L
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> v(p);
        for (auto& x : v) {
            cin >> x;
        }
        bool chk = false;
        for (int mask = 0; mask < (1 << p); ++mask) {
            int sum = 0;
            for (int j = 0; j < p; ++j) {
                if ((1 << j) & mask) {
                    sum += v[j];
                }
            }
            if (sum == n) {
                chk = true;
                break;
            }
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

