/**
 *    author:  MaGnsi0
 *    created: 27.10.2021 19:57:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
        cout << "1 1\n" << -a[0];
    } else {
        cout << "1 1 " << (long long)(n - 1) * a[0] << "\n";
        cout << "1 " << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << (long long)-n * a[i] << " ";
        }
        cout << "\n2 " << n << "\n";
        for (int i = 1; i < n; ++i) {
            cout << (long long)(n - 1) * a[i] << " ";
        }
    }
}
