/**
 *    author:  MaGnsi0
 *    created: 27.10.2021 20:25:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int sum = accumulate(a.begin(), a.end(), 0);
        if ((2 * a[0] > sum) || (sum & 1)) {
            cout << "T\n";
        } else {
            cout << "HL\n";
        }
    }
}
