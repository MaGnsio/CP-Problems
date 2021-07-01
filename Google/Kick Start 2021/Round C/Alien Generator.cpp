//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec1cb
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        long long G, X = 0;
        cin >> G;
        for (long long M = 1; M * M <= 2 * G; ++M) {
            long double K = G / (long double)M - M / 2.0 + 0.5;
            X += (K - (long long)K == 0);
        }
        cout << X << "\n";
    }
}
//N = A + (A + 1) + .... + (A + M - 1) = (M * A) + M * (M - 1) / 2 = M * (A + M / 2 - 0.5) -> A = N / M - M / 2 + 0.5
//-> A is postive integer -> if for every M : (N / M >= M / 2) -> if (N / M - M / 2 + 0.5) is an integer
//-> N is expressible as the sum of M consecutive positive integers
