//https://www.e-olymp.com/en/contests/15927/problems/164098
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            if (x) {
                cout << i << " " << j << "\n";
            }
        }
    }
}

