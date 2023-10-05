/**
 *    author:  MaGnsi0
 *    created: 07.02.2022 20:50:54
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
        vector<int> a(n, -1);
        for (int i = 1; i < n; ++i) {
            if ((i & (i - 1)) == 0) {
                a[0] = i;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] + 1 < n) {
                a[i] = a[i - 1] + 1;
            } else {
                reverse(a.begin(), a.begin() + i);
                for (int j = i; j < n; ++j) {
                    a[j] = j - i;
                }
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
