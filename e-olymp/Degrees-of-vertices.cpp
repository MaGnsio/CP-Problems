//https://www.e-olymp.com/en/contests/15927/problems/164109
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            cnt += x;
        }
        cout << cnt << "\n";
    }
}

