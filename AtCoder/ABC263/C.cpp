/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 21:45:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(1, 0);
    function<void()> solve = [&]() {
        if ((int)a.size() == n + 1) {
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
        }
        for (int i = a.back() + 1; i <= m; ++i) {
            a.push_back(i);
            solve();
            a.pop_back();
        }
    };
    solve();
}
