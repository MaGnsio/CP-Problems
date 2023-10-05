//https://codeforces.com/contest/1481/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        string s;
        cin >> x >> y >> s;
        vector<int> d(4, 0), k(4, 0);
        for (auto& c : s) {
            if (c == 'U')
                d[0]++;
            if (c == 'D')
                d[1]++;
            if (c == 'L')
                d[2]++;
            if (c == 'R')
                d[3]++;
        }
        if (x > 0)
            k[3] += x;
        else
            k[2] += abs (x);
        if (y > 0)
            k[0] += y;
        else
            k[1] += abs (y);
        bool chk = true;
        for (int i = 0; i < 4; ++i) {
            if (d[i] < k[i])
                chk = false;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}

