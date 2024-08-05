/**
 *    author:  MaGnsi0
 *    created: 13.05.2024 21:03:28
**/
#include <bits/stdc++.h>

using namespace std;

const int P = 10, B = 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int M; cin >> M;
    vector<int> posXBall(B, -1), posYBall(B, -1);
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
                } else if (cell[1] == 'B') {
                    posXBall[1] = i;
                    posYBall[1] = j;
                } else {
                    assert(cell[1] == 'S');
                    posXBall[2] = i;
                    posYBall[2] = j;
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
    function<void(int)> checkBludger = [&](int t) {
        if (posXBall[1] == -1 || posYBall[1] == -1) { return; }
        vector<string> toElimnate;
        for (int i = 0; i < P; ++i) {
            if (posXBall[1] == posXR[i] && posYBall[1] == posYR[i]) {
                toElimnate.push_back("R" + to_string(i));
                posXR[i] = posYR[i] = ballR[i] = -1;
            }
            if (posXBall[1] == posXB[i] && posYBall[1] == posYB[i]) {
                toElimnate.push_back("B" + to_string(i));
                posXB[i] = posYB[i] = ballB[i] = -1;
            }
        }
        sort(toElimnate.begin(), toElimnate.end());
        for (string p : toElimnate) {
            cout << t << " " << p << " ELIMINATED\n";
        }
    };
    int T; cin >> T;
    int scoreR = 0, scoreB = 0;
    for (int t = 0; t < T; ++t) {
        string p; cin >> p;
        string command; cin >> command;
        if (p[0] == '.') {
            int j = (p[1] == 'Q' ? 0 : (p[1] == 'B' ? 1 : 2));
            if (command == "U") {
                posXBall[j]--;
            } else if (command == "D") {
                posXBall[j]++;
            } else if (command == "L") {
                posYBall[j]--;
            } else if (command == "R") {
                posYBall[j]++;
            } else { assert(-1); }
            checkBludger(t);
            continue;
        }
        int j = p[1] - '0';
        if (command == "C") {
            string ball; cin >> ball;
            int ballj = (ball[1] == 'Q' ? 0 : 2);
            if (p[0] == 'R') {
                ballR[j] = ballj;
            } else {
                ballB[j] = ballj; 
            }
            if (ballj == 2) {
                cout << t << " " << (p[0] == 'B' ? "BLUE" : "RED") << " CATCH GOLDEN SNITCH\n";
                if (p[0] == 'R') {
                    scoreB += 10;
                } else {
                    scoreR += 10;
                }
                break;
            }
        } else if (command == "T") {
            int ballj = (p[0] == 'R' ? ballR[j] : ballB[j]);
            assert(ballj == 0);
            if (p[0] == 'R') {
                ballR[j] = -1;
            } else {
                ballB[j] = -1;
            }
            int x = posXBall[ballj];
            int y = posYBall[ballj];
            if (isGoalR[x][y]) {
                cout << t << " BLUE GOAL\n";
                posXBall[ballj] = N / 2;
                posYBall[ballj] = M / 2;
                scoreR++;
            } else if (isGoalB[x][y]) {
                cout << t << " RED GOAL\n";
                posXBall[ballj] = N / 2;
                posYBall[ballj] = M / 2;
                scoreB++;
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
            checkBludger(t);
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
            checkBludger(t);
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
            checkBludger(t);
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
            checkBludger(t);
        } else { assert(-1); }
    }
    cout << "FINAL SCORE: " << scoreB << " " << scoreR << "\n";
}
