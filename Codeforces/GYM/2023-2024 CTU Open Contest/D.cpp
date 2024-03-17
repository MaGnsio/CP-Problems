/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 20:39:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q; cin.ignore();
    string s, t; getline(cin, s);
    vector<string> in;
    stringstream sin(s);
    while (sin >> t) {
        in.push_back(t);
    }
    int sign = +1;
    vector<int> groups, group_sign, number_group, number;
    for (int i = 0; i < (int)in.size(); /*_*/) {
        int j = i;
        groups.push_back(0);
        group_sign.push_back(sign);
        while (j < (int)in.size() && in[j] != "+" && in[j] != "-") {
            if (in[j] == "*") { j++; continue; }
            groups.back() += stoi(in[j]) % 2 == 0;
            number_group.push_back((int)groups.size() - 1);
            number.push_back(stoi(in[j]) % 2);
            j++;
        }
        if (j < (int)in.size()) { sign = (in[j] == "+" ? +1 : -1); }
        i = j + 1;
    }
    int m = (int)groups.size(), sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += group_sign[i] * (groups[i] == 0);
    }
    cout << (sum % 2 ? "odd" : "even") << "\n";
    while (Q--) {
        int i; cin >> i; i--;
        int value; cin >> value; value %= 2;
        int j = number_group[i];
        if (number[i] != value) {
            sum -= group_sign[j] * (groups[j] == 0);
            if (value) {
                groups[j]--;
            } else {
                groups[j]++;
            }
            number[i] = value;
            sum += group_sign[j] * (groups[j] == 0);
        }
        cout << (sum % 2 ? "odd" : "even") << "\n";
    }
}
