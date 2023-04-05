/**
 *    author:  MaGnsi0
 *    created: 16.02.2023 15:37:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t x;
    vector<long double> ans;
    while (cin >> x) {
        ans.push_back(sqrt(x));
    }
    reverse(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << fixed << setprecision(4) << x << "\n";
    }
}
