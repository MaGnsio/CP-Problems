//https://codeforces.com/gym/102680/problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> t(1500, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            t[x]++, t[x + s]--;
        }
        for (int i = 1; i < 1500; ++i) {
            t[i] += t[i - 1];
        }
        bool chk = true;
        for (auto& x : t) if (x > 1) {
            chk = false;
            break;
        }
        cout << (chk ? "NO\n" : "YES\n");
    }
}

