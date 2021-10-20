//https://codeforces.com/gym/102323/problem/F
#include <bits/stdc++.h>
using namespace std;

pair<int, string> Solve(int t) {
    int X = t / 60, Y = t % 60, N = 0, Cnt = INT_MAX;
    pair<int, string> F = {INT_MAX, ""};
    while (Y + N * 60 <= 99 && X - N >= 0) {
        int U = X - N, V = Y + N * 60;
        string A = to_string(U), B = to_string(V), K;
        if (B.size() == 1) {
            B.insert(B.begin(), '0');
        }
        if (U) {
            K = A + B;
        } else {
            K = B;
        }
        int Cur = 1;
        for (int i = 1; i < K.size(); ++i) {
            if (K[i] == K[i - 1]) {
                Cur++;
            } else {
                Cur += 2;
            }
        }
        if (Cur < Cnt) {
            F = {Cur, K};
            Cnt = Cur;
        }
        N++;
    }
    return F;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int P;
        string S;
        cin >> S >> P;
        int All = 60 * (10 * (S[0] - '0') + (S[1] - '0')) + 10 * (S[3] - '0') + (S[4] -'0');
        int X = All * P / 100;
        int K = 0;
        pair<int, string> ANS = {INT_MAX, ""};
        for (int i = All - X; i <= All + X; ++i) {
            pair<int, string> Temp = Solve(i);
            if ((Temp.first < ANS.first) || (Temp.first == ANS.first && abs(All - i) < K)) {
                ANS = Temp;
                K = abs(All - i);
            }
        }
        cout << ANS.second << "\n";
    }
}
