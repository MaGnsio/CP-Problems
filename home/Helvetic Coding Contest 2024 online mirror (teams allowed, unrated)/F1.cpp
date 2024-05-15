/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 20:26:07
**/
#include <bits/stdc++.h>

using namespace std;

const int P = 10, B = 1;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int M; cin >> M;
    vector<int> posXBall(B), posYBall(B);
    vector<int> posXR(P, -1), posYR(P, -1), ballR(P, -1);
    vector<int> posXB(P, -1), posYB(P, -1), ballB(P, -1);
    vector<vector<bool>> isGoalR(N, vector<bool>(M, false));
    vector<vector<bool>> isGoalB(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            string cell; cin >> cell;
            if (cell == "..") { continue; }
            if (cell[0] == '.') {
                if (cell[1] == 'Q') {
                    posXBall[0] = i;
                    posYBall[0] = j;
                }
            } else if (cell[0] == 'R') {
                if (cell[1] == 'G') {
                    isGoalR[i][j] = true;
                } else {
                    posXR[cell[1] - '0'] = i;
                    posYR[cell[1] - '0'] = j;
                }
            } else {
                assert(cell[0] == 'B');
                if (cell[1] == 'G') {
                    isGoalB[i][j] = true;
                } else {
                    posXB[cell[1] - '0'] = i;
                    posYB[cell[1] - '0'] = j;
                }
            }
        }
    }
    int T; cin >> T;
    int scoreR = 0, scoreB = 0;
    for (int t = 0; t < T; ++t) {
        string p; cin >> p;
        string command; cin >> command;
        int j = p[1] - '0';
        if (command == "C") {
            string ball; cin >> ball;
            int ballj = (ball[1] == 'Q' ? 0 : -1);
            if (p[0] == 'R') {
                ballR[j] = ballj;
            } else {
                ballB[j] = ballj; 
            }
        } else if (command == "T") {
            int ballj = (p[0] == 'R' ? ballR[j] : ballB[j]);
            if (p[0] == 'R') {
                ballR[j] = -1;
            } else {
                ballB[j] = -1;
            }
            int x = posXBall[ballj];
            int y = posYBall[ballj];
            if (isGoalR[x][y]) {
                cout << t << " BLUE GOAL\n";
                scoreR++;
                posXBall[ballj] = N / 2;
                posYBall[ballj] = M / 2;
            } else if (isGoalB[x][y]) {
                cout << t << " RED GOAL\n";
                scoreB++;
                posXBall[ballj] = N / 2;
                posYBall[ballj] = M / 2;
            }
        } else if (command == "U") {
            if (p[0] == 'R') {
                posXR[j]--;
                if (ballR[j] != -1) {
                    posXBall[ballR[j]]--;
                }
            } else {
                posXB[j]--;
                if (ballB[j] != -1) {
                    posXBall[ballB[j]]--;
                }
            }
        } else if (command == "D") {
            if (p[0] == 'R') {
                posXR[j]++;
                if (ballR[j] != -1) {
                    posXBall[ballR[j]]++;
                }
            } else {
                posXB[j]++;
                if (ballB[j] != -1) {
                    posXBall[ballB[j]]++;
                }
            }
        } else if (command == "L") {
            if (p[0] == 'R') {
                posYR[j]--;
                if (ballR[j] != -1) {
                    posYBall[ballR[j]]--;
                }
            } else {
                posYB[j]--;
                if (ballB[j] != -1) {
                    posYBall[ballB[j]]--;
                }
            }
        } else if (command == "R") {
            if (p[0] == 'R') {
                posYR[j]++;
                if (ballR[j] != -1) {
                    posYBall[ballR[j]]++;
                }
            } else {
                posYB[j]++;
                if (ballB[j] != -1) {
                    posYBall[ballB[j]]++;
                }
            }
        } else { assert(-1); }
    }
    cout << "FINAL SCORE: " << scoreB << " " << scoreR << "\n";
}
