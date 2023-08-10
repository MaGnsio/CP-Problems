/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 18:28:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        even += a[i] % 2 == 0;
        odd += a[i] % 2 == 1;
    }
    cout << (min(even, odd) % 2 == 1 ? "Odd" : "Even");
}
