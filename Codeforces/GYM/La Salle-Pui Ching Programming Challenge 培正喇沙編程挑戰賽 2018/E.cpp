/**
 *    author:  MaGnsi0
 *    created: 11/08/2021 11:25:40
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    do {
        int sum = 0, ok = 1;
        for (int i = 0; i < n; ++i) {
            sum += v[i];
            if (sum > 99999999 || sum < 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << v[i] << "\n";
            }
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << "Error";
}
