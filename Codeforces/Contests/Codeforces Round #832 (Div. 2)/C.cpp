/**
 *    author:  MaGnsi0
 *    created: 04.11.2022 16:47:16
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
        int64_t mine = *min_element(a.begin(), a.end());
        cout << (a[0] > mine ? "Alice" : "Bob") << "\n";
    }
}
