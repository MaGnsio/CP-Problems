//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ebe5e
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int N, K;
        string S;
        cin >> N >> K >> S;
        long long ANS = 0;
        for (int i = 0; i < (N + 1) / 2; ++i) {
            ANS = (ANS * K + S[i] - 'a') % mod;
        }
        for (int i = 0; i < N / 2; ++i) {
            if (S[N / 2 - i - 1] == S[(N + 1) / 2 + i]) {
                continue;
            }
            if (S[N / 2 - i - 1] < S[(N + 1) / 2 + i]) {
                ANS = (ANS + 1) % mod;
                break;
            }
            break;
        }
        cout << ANS << "\n";
    }
}
