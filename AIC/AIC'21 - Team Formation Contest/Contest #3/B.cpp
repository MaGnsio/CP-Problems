/**
 *    author:  MaGnsi0
 *    created: 18/07/2021 13:22:51
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<string> s = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    vector<int> v;
    v.push_back(0);
    v.push_back(5);
    int k = 10;
    while (k <= 1000000000) {
        v.push_back(k);
        k *= 2;
    }
    for (int i = 1; i <= v.size(); ++i) {
        v[i] += v[i - 1];
    }
    for (int i = 1, c = 1; i < v.size(); ++i, c *= 2) {
        if (v[i] >= n) {
            int x = n - v[i - 1];
            int y = (x + c - 1) / c;
            for (int j = 0; j < 5; ++j) {
                if (y == j + 1) {
                    cout << s[j];
                    return 0;
                }
            }
        }
    }
}
