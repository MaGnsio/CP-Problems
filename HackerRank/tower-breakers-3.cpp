/**
 *    author:  MaGnsi0
 *    created: 22.09.2022 00:24:13
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> grundy(N);
    function<int(vector<int>)> mex = [](vector<int> a) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        for (int i = 0; i < (int)a.size(); ++i) {
            if (a[i] != i) {
                return i;
            }
        }
        return (int)a.size();
    };
    for (int i = 2; i < N; ++i) {
        vector<int> a;
        a.push_back(grundy[1]);
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                a.push_back(((i / j) & 1 ? grundy[j] : 0));
                a.push_back(((j) & 1 ? grundy[i / j] : 0));
            }
        }
        grundy[i] = mex(a);
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int nimber = 0;
        for (int i = 0; i < n; ++i) {
            nimber ^= grundy[a[i]];
        }
        cout << (nimber ? 1 : 2) << "\n";
    }
}
