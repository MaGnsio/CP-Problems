//https://codeforces.com/contest/776/problem/B
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
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
    if (N < 3) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
    for (int i = 2; i <= N + 1; ++i) {
        if (is_prime(i)) {
            cout << 1 << " ";
        } else {
            cout << 2 << " ";
        }
    }
}
