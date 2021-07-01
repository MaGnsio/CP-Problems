/**
 *    author:  MaGnsi0
 *    created: 03/06/2021 22:25:05
**/
#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<int> V;
    for (int i = 2; i <= 55555; ++i) {
        if (is_prime(i)) {
            V.push_back(i);
        }
    }
    for (int i = 0, j = 0; j < N; ++i) {
        if (V[i] % 5 == 1) {
            cout << V[i] << " ";
            j++;
        }
    }
}
