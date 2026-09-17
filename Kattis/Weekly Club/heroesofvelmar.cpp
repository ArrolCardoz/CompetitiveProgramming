#include <bits/stdc++.h>
using namespace std;

int power[6] = {0};

struct card {
  string name;
  int energy_cost;
  int power_level;
  int abilityID;
};

unordered_map<string, int> cardNameToID = {
    {"Shadow", 0},   {"Gale", 1},     {"Ranger", 2},       {"Anvil", 3},
    {"Vexia", 4},    {"Guardian", 5}, {"Thunderheart", 6}, {"Frostwhisper", 7},
    {"Voidclaw", 8}, {"Ironwood", 9}, {"Zenith", 10},      {"Seraphina", 11}};

const card Cards[12] = {{"Shadow", 4, 6, 0},       {"Gale", 3, 5, 0},
                        {"Ranger", 2, 4, 0},       {"Anvil", 5, 7, 0},
                        {"Vexia", 2, 3, 0},        {"Guardian", 6, 8, 0},
                        {"Thunderheart", 5, 6, 1}, {"Frostwhisper", 1, 2, 0},
                        {"Voidclaw", 1, 3, 0},     {"Ironwood", 1, 3, 0},
                        {"Zenith", 6, 4, 2},       {"Seraphina", 1, 1, 3}};

void printBoard(vector<int> board[]) {
  for (int i = 0; i < 6; i++) {
    for (auto& a : board[i]) cout << a << ' ';
    cout << endl;
  }
}

void applyAbility(vector<int> board, int level, int _abilityID) {
  switch (_abilityID) {
    case 1:
      if (board.size() >= 4) {
        // power[level] += Cards[cardNameToID["Thunderheart"]].power_level;
        power[level] += 6;
      }
      break;
    case 2:
      if (level == 1 || level == 4) power[level] += 5;
      break;
    case 3:
      power[level] += board.size() - 1;
      break;
  }
}

void locationResolution(vector<int> board[]) {
  for (int i = 0; i < 6; i++) {
    for (auto& a : board[i]) {
      // check if has special ability
      if (Cards[a].abilityID) {
        applyAbility(board[i], i, Cards[a].abilityID);
      }
      power[i] += Cards[a].power_level;
    }
  }
}

void printPower() {
  for (auto& it : power) {
    cout << "POWER: " << it << endl;
  }
}

void finalScore() {
  int p1score = 0, p2score = 0;
  int p1TotalScore = 0, p2TotalScore = 0;
  for (int i = 0; i < 3; i++) {
    p1TotalScore += power[i];
    p2TotalScore += power[i + 3];
    if (power[i] > power[i + 3])
      p1score++;
    else if (power[i] < power[i + 3])
      p2score++;
    // cerr << p1score << ' ' << p2score << endl;
    // cerr << power[i] << ' ' << power[i + 3] << endl;
  }
  // cerr << "TEST SCORE PLAYER1 " << p1score << " PLAYER 2: " << p2score <<
  // endl;
  if (p1score > p2score)
    cout << "Player 1" << endl;
  else if (p1score < p2score)
    cout << "Player 2" << endl;
  else {
    // tie
    if (p1TotalScore > p2TotalScore)
      cout << "Player 1" << endl;
    else if (p1TotalScore < p2TotalScore)
      cout << "Player 2" << endl;
    else
      cout << "Tie" << endl;
  }
}

int main() {
  vector<int> board[6];
  // 0 1 2 p1
  // 3 4 5 p2

  // i didn't understand input so this is the bandaid fix
  for (int i = 0; i < 6; i++) {
    int n;
    cin >> n;
    string input;
    int x = 0;
    switch (i) {
      case 0:
        x = 0;
        break;
      case 1:
        x = 3;
        break;
      case 2:
        x = 1;
        break;
      case 3:
        x = 4;
        break;
      case 4:
        x = 2;
        break;
      case 5:
        x = 5;
        break;
    }
    board[x].resize(n);
    for (auto& it : board[x]) {
      cin >> input;
      it = cardNameToID[input];
    }
  }
  // Location Resolution
  locationResolution(board);
  // count score
  finalScore();
  // printBoard(board);
  // printPower();
  return 0;
}