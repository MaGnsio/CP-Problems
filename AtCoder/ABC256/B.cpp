/**
 *    author:  MaGnsi0
 *    created: 18.06.2022 14:03:29
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
    int ans = 0;
    vector<int> s(4, 0);
    for (int i = 0; i < n; ++i) {
        s[0]++;
        vector<int> ns(4, 0);
        for (int j = 0; j < 4; ++j) {
            if (j + a[i] < 4) {
                ns[j + a[i]] = s[j];
            }
        }
        s = ns;
    }
    cout << n - accumulate(s.begin(), s.end(), 0);
}
