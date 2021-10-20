//https://vjudge.net/contest/436257#problem/B
#include <bits/stdc++.h>
using namespace std;

bool solve(string A, string B) {
    if (A == B) {
        return true;
    }
    string X = A, Y = B;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    if ((A.size() & 1) || (X != Y)) {
        return false;
    }
    string A1 = A.substr(0, A.size() / 2), A2 = A.substr(A.size() / 2, A.size() / 2);
    string B1 = B.substr(0, B.size() / 2), B2 = B.substr(B.size() / 2, B.size() / 2);
    return ((solve(A1, B1) && solve(A2, B2)) || (solve(A1, B2) && solve(A2, B1)));
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string A, B;
    cin >> A >> B;
    cout << (solve(A, B) ? "YES" : "NO");
}

