//https://atcoder.jp/contests/abc201/tasks/abc201_c
#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int>& V, string s) {
    for (int i = 0; i < 10; ++i) {
        if ((V[i] == 1 && count(s.begin(), s.end(), '0' + i) == 0) || (V[i] == 0 && count(s.begin(), s.end(), '0' + i) != 0)) {
            return false;
        }
    }
    return true;
}

void fill(vector<string>& S, string s = "") {
    if(s.size() == 4) {
        S.push_back(s);
        return;
    }
    for (char i = '0'; i <= '9'; ++i) {
        fill(S, s + i);
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<string> S;
    fill(S);
    int N = 0;
    vector<int> V(10, 0);
    for (int i = 0; i < 10; ++i) {
        char x;
        cin >> x;
        if (x == 'o') {
            V[i] = 1;
        } else if (x == '?') {
            V[i] = -1;
        }
    }
    for (int i = 0; i < S.size(); ++i) {
        if (valid(V, S[i])) {
            N++;
        }
    }
    cout << N;
}
