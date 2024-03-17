/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 14:14:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    function<void(int, int)> solve = [&](int low, int high) {
        if (low == high) {
            cout << "! " << low << endl;
            exit(0);
        }
        int mid = (low + high) / 2;
        cout << low << " " << mid << endl;
        int x; cin >> x;
        if (x) {
            solve(low, mid);
        } else {
            solve(mid + 1, high);
        }
    };
    solve(1, n);
}
