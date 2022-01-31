/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 20:43:47
**/
#include <bits/stdc++.h>

using namespace std;

struct T {
    string H, M, S;
    T(string H, string M, string S) {
        this -> H = H;
        this -> M = M;
        this -> S = S;
    }
};

void inc(T& x) {
    int h = stoi(x.H);
    int m = stoi(x.M);
    int s = stoi(x.S);
    if (s < 59) {
        s++;
    } else {
        s = 0;
        if (m < 59) {
            m++;
        } else {
            m = 0;
            h++;
        }
    }
    x.H = to_string(h);
    x.M = to_string(m);
    x.S = to_string(s);
    if ((int)x.H.size() < 2) {
        x.H.insert(x.H.begin(), '0');
    }
    if ((int)x.M.size() < 2) {
        x.M.insert(x.M.begin(), '0');
    }
    if ((int)x.S.size() < 2) {
        x.S.insert(x.S.begin(), '0');
    }
}

int diff(T a, T b) {
    int h1 = stoi(a.H);
    int m1 = stoi(a.M);
    int s1 = stoi(a.S);
    int h2 = stoi(b.H);
    int m2 = stoi(b.M);
    int s2 = stoi(b.S);
    return (h1 * 60 * 60 + m1 * 60 + s1) - (h2 * 60 * 60 + m2 * 60 + s2);
}

T solve(T& x, vector<T>& valids) {
    int l = 0, r = (int)valids.size() - 1;
    T behind("-1", "-1", "-1");
    while (l <= r) {
        int m = (l + r) / 2;
        if (diff(valids[m], x) <= 0) {
            behind = valids[m];
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    l = 0, r = (int)valids.size() - 1;
    T ahead("-1", "-1", "-1");
    while (l <= r) {
        int m = (l + r) / 2;
        if (diff(valids[m], x) >= 0) {
            ahead = valids[m];
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (ahead.H == "-1") {
        return behind;
    }
    if (behind.H == "-1") {
        return ahead;
    }
    if (abs(diff(behind, x)) <= abs(diff(ahead, x))) {
        return behind;
    } else {
        return ahead;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d;
    cin >> d;
    vector<char> a(d);
    for (int i = 0; i < d; ++i) {
        cin >> a[i];
    }
    auto valid = [&](T y) {
        for (int i = 0; i < d; ++i) {
            if (y.H.find(a[i]) != string::npos) {
                return false;
            }
            if (y.M.find(a[i]) != string::npos) {
                return false;
            }
            if (y.S.find(a[i]) != string::npos) {
                return false;
            }
        }
        return true;
    };
    vector<T> valids;
    for (T x("00", "00", "00"); x.H != "60"; inc(x)) {
        if (valid(x)) {
            valids.push_back(x);
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int k;
        string s;
        cin >> k >> s;
        T x("", "", "");
        x.H = s.substr(0, 2);
        x.M = s.substr(3, 2);
        x.S = s.substr(6, 2);
        x = solve(x, valids);
        cout << k << " " << x.H << ":" << x.M << ":" << x.S << "\n";
    }
}
