/**
 *    author:  MaGnsi0
 *    created: 19.09.2023 19:51:48
**/
#include <bits/stdc++.h>

using namespace std;

const string S = "UUUUUCUUAUUGCUUCUCCUACUGAUUAUCAUAAUGGUUGUCGUAGUGUCUUCCUCAUCGAGUAGCCCUCCCCCACCGACUACCACAACGGCUGCCGCAGCGUAUUACCAUCACCAACAGAAUAACAAAAAGGAUGACGAAGAGUGUUGCUGGCGUCGCCGACGGAGAAGGGGUGGCGGAGGGUAAUAGUGA";

const pair<string, int> AC[] = {{"F", 2}, {"L", 6}, {"I", 3}, {"M", 1}, {"V", 4}, {"S", 6}, {"P", 4}, {"T", 4}, {"A", 4}, {"Y", 2}, {"H", 2}, {"Q", 2}, {"N", 2}, {"K", 2}, {"D", 2}, {"E", 2}, {"C", 2}, {"W", 1}, {"R", 6}, {"G", 4}, {"STOP", 3}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, string> MP;
    for (int i = 0, j = 0, k = 0; i < (int)S.size(); i += 3) {
        MP[S.substr(i, 3)] = AC[j].first;
        if (k + 1 == AC[j].second) {
            k = 0, j++;
        } else {
            k++;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        string X;
        cin >> X;
        string Y = "";
        for (int i = 0; i < (int)X.size(); i += 3) {
            string RNA = MP[X.substr(i, 3)];
            if (RNA == "STOP") { break; }
            Y += RNA;
        }
        cout << Y << "\n";
    }
}
