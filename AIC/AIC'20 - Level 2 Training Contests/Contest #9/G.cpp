//https://vjudge.net/contest/435043#problem/G
#include<iostream>
#include<string>
using namespace std;

int f[] = {0, 0, 1, 3, 9, 27, 81, 243};

string solve (int N) {
    if (N == 1) {
        return "X\n";
    }
    int x;
    string X = solve(N - 1);
    string S = "";
    for (int i = 0, l = 0; i < X.size(); ++i) {
        if (X[i] == '\n') {
            if (l == 0) {
                x = X.substr(l, i - l).size();
            }
            S += X.substr(l, i - l);
            for (int j = 0; j < f[N] + (x - X.substr(l, i - l).size()); ++j) {
                S += " ";
            }
            S += X.substr(l, i - l);
            S += "\n";
            l = i + 1;
        }
    }
    for (int i = 0, l = 0; i < X.size(); ++i) {
        if (X[i] == '\n') {
            for (int j = 0; j < f[N]; ++j) {
                S += " ";
            }
            S += X.substr(l, i - l);
            S += "\n";
            l = i + 1;
        }
    }
    for (int i = 0, l = 0; i < X.size(); ++i) {
        if (X[i] == '\n') {
            if (l == 0) {
                x = X.substr(l, i - l).size();
            }
            S += X.substr(l, i - l);
            for (int j = 0; j < f[N] + (x - X.substr(l, i - l).size()); ++j) {
                S += " ";
            }
            S += X.substr(l, i - l);
            S += "\n";
            l = i + 1;
        }
    }
    return S;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while ((cin >> N) && (N != -1)) {
        string S = solve(N);
        cout << S << "-\n";
    }
}

