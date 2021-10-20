//https://www.e-olymp.com/en/contests/15927/problems/164106
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, cnt = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp = 0;
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            temp += x;
        }
        cnt += (temp == 1);
    }
    cout << cnt;
}

