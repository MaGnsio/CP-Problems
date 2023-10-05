/**
 *    author:  MaGnsi0
 *    created: 12.12.2022 18:53:01
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> A;
    for (int i = 1; i < N; ++i) {
        int x = i, cnt = 0;
        while (x) {
            cnt += (x % 10 != 0);
            x /= 10;
        }
        if (cnt == 1) {
            A.push_back(i);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << int(upper_bound(A.begin(), A.end(), n) - A.begin()) << "\n";
    }
}
