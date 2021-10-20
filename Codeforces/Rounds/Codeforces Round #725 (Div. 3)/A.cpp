/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:23:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
        }
        int mini = *min_element(v.begin(), v.end()), maxi = *max_element(v.begin(), v.end());
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            a++;
            if (v[i] == mini) {
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            b++;
            if (v[i] == maxi) {
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            c++;
            if (v[i] == mini) {
                break;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            d++;
            if (v[i] == maxi) {
                break;
            }
        }
        cout << min({max(a, b), max(c, d), a + d, b + c})  << "\n";
    }
}
