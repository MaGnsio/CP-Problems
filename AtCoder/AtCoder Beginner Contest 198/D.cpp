//https://atcoder.jp/contests/abc198/tasks/abc198_d
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    set<char> S;
    for (auto& x : S1)
        S.insert (x);
    for (auto& x : S2)
        S.insert (x);
    for (auto& x : S3)
        S.insert (x);
    if (S.size () > 10) {
        cout << "UNSOLVABLE";
        return 0;
    }
    vector<int> V(10);
    iota (V.begin (), V.end (), 0);
    vector<char> N;
    for (auto& x : S) N.push_back (x);
    do {
        string A = S1, B = S2, C = S3;
        map<char, int> M;
        for (int i = 0; i < N.size (); ++i) {
            M[N[i]] = V[i];
        }
        for (auto& x : A) {
            x = '0' + M[x];
        }
        for (auto& x : B) {
            x = '0' + M[x];
        }
        for (auto& x : C) {
            x = '0' + M[x];
        }
        if (stoll (A) + stoll (B) == stoll (C) && A[0] != '0' && B[0] != '0' && C[0] != '0') {
            cout << A << "\n" << B << "\n" << C;
            return 0;
        }
    } while (next_permutation (V.begin (), V.end ()));
    cout << "UNSOLVABLE";
}

