//https://codeforces.com/gym/102875/problem/C
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N = (1 << 20) - 1, M = (1 << 19), P = 2;
    vector<int> V(N, 0);
    for (int i = 20; i > 0; --i) {
        int j;
        for (j = 0; j < N; ++j) {
            if (V[j] == 0) {
                break;
            }
        }
        for (int k = M; j < N && k; j += P) {
            V[j] = i;
            k--;
        }
        P *= 2, M /= 2;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << V[i] << " ";
    }
}

