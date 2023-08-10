/**
 *    author:  MaGnsi0
 *    created: 03.04.2023 22:40:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<string> candidate(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidate[i];
    }
    map<string, int> I;
    for (int i = 0; i < N; ++i) {
        I[candidate[i]] = i;
    }
    vector<int> X(M);
    vector<vector<string>> votes(M);
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
        votes[i].resize(X[i]);
        for (int j = 0; j < X[i]; ++j) {
            cin >> votes[i][j];
        }
    }
    vector<int> cur_vote(M, 0), candidate_score(N, 0);
    set<string> eliminated;
    set<tuple<int, int, string>> ranking;
    for (int i = 0; i < N; ++i) {
        ranking.emplace(0, i, candidate[i]);
    }
    for (int i = 0; i < M; ++i) {
        string x = votes[i][cur_vote[i]];
        int y = I[x], z = candidate_score[y];
        ranking.erase(make_tuple(z, y, x));
        cur_vote[i]++, candidate_score[y]++;
        ranking.emplace(candidate_score[y], y, x);
    }
    while (eliminated.size() != N - 1) {
        eliminated.emplace(get<2>(*ranking.begin()));
        ranking.erase(ranking.begin());
        for (int i = 0; i < M; ++i) {
            if (eliminated.count(votes[i][cur_vote[i] - 1]) == 0) { continue; }
            while (cur_vote[i] < X[i] && eliminated.count(votes[i][cur_vote[i]]) == 1) { cur_vote[i]++; }
            if (cur_vote[i] < X[i]) {
                string x = votes[i][cur_vote[i]];
                int y = I[x], z = candidate_score[y];
                ranking.erase(make_tuple(z, y, x));
                cur_vote[i]++, candidate_score[y]++;
                ranking.emplace(candidate_score[y], y, x);
            }
        }
    }
    assert(ranking.size() == 1);
    string winner = "";
    for (int i = 0; i < N; ++i) {
        if (eliminated.count(candidate[i]) == 0) {
            winner = candidate[i];
        }
    }
    cout << winner << endl;
}
