//https://codeforces.com/gym/102757/problem/D
#include <bits/stdc++.h>
using namespace std;

int getM(string m) {
    if (m == "Jan") {
        return 1;
    } else if (m == "Feb") {
        return 2;
    } else if (m == "Mar") {
        return 3;
    } else if (m == "Apr") {
        return 4;
    } else if (m == "May") {
        return 5;
    } else if (m == "Jun") {
        return 6;
    } else if (m == "Jul") {
        return 7;
    } else if (m == "Aug") {
        return 8;
    } else if (m == "Sep") {
        return 9;
    } else if (m == "Oct") {
        return 10;
    } else if (m == "Nov") {
        return 11;
    } else if (m == "Dec") {
        return 12;
    }
}

bool comp(int d, int m, int y) {
    if (y > 1928) {
        return true;
    } else if (y == 1928 && m > 7) {
        return true;
    } else if (y == 1928 && m == 7 && d > 7) {
        return true;
    } else {
        return false;
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    string S;
    int D, M, Y;
    double maxG = 1e-9;
    for (int i = 0; i < N; ++i) {
        string s;
        cin.ignore();
        getline(cin, s);
        string a, b, c;
        cin >> b >> a >> c;
        double g;
        cin >> g;
        a.erase(a.size() - 1, 1);
        int d = stoi(a), m = getM(b), y = stoi(c);
        if (comp(d, m, y)) {
            if (g > maxG) {
                S = s;
                D = d, M = m, Y = y;
                maxG = g;
            }
        }
    }
    cout << S;
}
