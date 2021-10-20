//https://www.e-olymp.com/en/contests/15927/problems/164095
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, E = 0;
    cin >> N;
    for (int i = 0; i < N * N; ++i) {
        int X;
        cin >> X;
        E += X;
    }
    cout << E;
}

