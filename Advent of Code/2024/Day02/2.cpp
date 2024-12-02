/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 19:31:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string in;
    int ans = 0;
    while (getline(cin, in)) {
        stringstream sin(in);
        int x;
        vector<int> a;
        while (sin >> x) {
            a.push_back(x);
        }
        int n = (int)a.size();
        vector<bool> incp(n, true), decp(n, true), diffp(n, true);
        vector<bool> incs(n, true), decs(n, true), diffs(n, true);
        for (int i = 1; i < n; ++i) {
            decp[i] = a[i] <= a[i - 1];
            incp[i] = a[i] >= a[i - 1];
            diffp[i] = 1 <= abs(a[i] - a[i - 1]) && abs(a[i] - a[i - 1]) <= 3;
        }
        for (int i = n - 2; i >= 0; --i) {
            decs[i] = a[i] >= a[i + 1];
            incs[i] = a[i] <= a[i + 1];
            diffs[i] = 1 <= abs(a[i] - a[i + 1]) && abs(a[i] - a[i + 1]) <= 3;
        }
        for (int i = 1; i < n; ++i) {
            decp[i] = decp[i] && decp[i - 1];
            incp[i] = incp[i] && incp[i - 1];
            diffp[i] = diffp[i] && diffp[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            decs[i] = decs[i] && decs[i + 1];
            incs[i] = incs[i] && incs[i + 1];
            diffs[i] = diffs[i] && diffs[i + 1];
        }
        if (diffp[n - 1] && (incp[n - 1] || decp[n - 1])) {
            ans++;
            continue;
        }
        bool good = false;
        for (int i = 0; i < n; ++i) {
            bool dec = (i == 0 || i + 1 == n ? true : a[i + 1] <= a[i - 1]);
            bool inc = (i == 0 || i + 1 == n ? true : a[i + 1] >= a[i - 1]);
            bool diff = (i == 0 || i + 1 == n ? true : 1 <= abs(a[i + 1] - a[i - 1]) && abs(a[i + 1] - a[i - 1]) <= 3); 
            good |= ((i == 0 ? true : diffp[i - 1]) && diff && (i + 1 == n ? true : diffs[i + 1])) && (((i == 0 ? true : decp[i - 1]) && dec && (i + 1 == n ? true : decs[i + 1])) || ((i == 0 ? true : incp[i - 1]) && inc && (i + 1 == n ? true : incs[i + 1])));
        }
        ans += good;
    }
    cout << ans;
}
