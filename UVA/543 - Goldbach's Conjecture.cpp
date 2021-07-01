//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484
#include <bits/stdc++.h>
using namespace std;

void seive(int n, vector<bool>& is_prime, vector<int>& prime, vector<int>& mark) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j < n; j += i) {
                is_prime[j] = false;
                mark[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int maxN = 1e6 + 3;
    vector<int> prime, mark(maxN, 1);
    vector<bool> is_prime(maxN, true);
    seive(maxN, is_prime, prime, mark);
    int N;
    while ((cin >> N) && N) {
        for (int i = 0; i < prime.size(); ++i) {
            int x = prime[i], y = N - prime[i];
            if (x > y) {
                break;
            }
            if (mark[y] && mark[x]) {
                cout << N << " = " << x << " + " << y << "\n";
                break;
            }
        }
    }
}
