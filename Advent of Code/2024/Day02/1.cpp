/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 19:26:43
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
        bool dec = true, inc = true, diff = true;
        for (int i = 1; i < n; ++i) {
            dec = dec && a[i] <= a[i - 1];
            inc = inc && a[i] >= a[i - 1];
            diff = diff && 1 <= abs(a[i] - a[i - 1]) && abs(a[i] - a[i - 1]) <= 3;
        }
        ans += diff && (inc || dec);
    }
    cout << ans;
}
