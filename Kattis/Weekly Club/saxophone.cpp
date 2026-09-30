#include <bits/stdc++.h>
using namespace std;

// I used bit manipulation to solve this problem
// A few tables --
// notes which is the order of in notes in the table idxOfNote
// idxOfNote is used to get which button are pressed in the "button" table
// or the bitmask of those buttons in the "bitmask" table
// I initilize the index and bitmask in the init function
//------------------------------------------------------------------------------
// solution
//  for the solution I use logic operators to get which new buttons are not
//  pressed buttonNotBeginPressed = ButtonsPressed AND (NOT(ButtonsToBePressed))
// finally I count the bits of "buttonNotBeginPressed" in the countBits function
// Where answer is stored in a vector of size 10 where the index repesents the
// button number
string notes = "cdefgabCDEFGAB";
vector<vector<int>> buttons = {{2, 3, 4, 7, 8, 9, 10},
                               {2, 3, 4, 7, 8, 9},
                               {2, 3, 4, 7, 8},
                               {2, 3, 4, 7},
                               {2, 3, 4},
                               {2, 3},
                               {2},
                               {3},
                               {1, 2, 3, 4, 7, 8, 9},
                               {1, 2, 3, 4, 7, 8},
                               {1, 2, 3, 4, 7},
                               {1, 2, 3, 4},
                               {1, 2, 3},
                               {1, 2}};
vector<int> bitmask(14, 0);
unordered_map<char, int> idxOfNote;

void init() {
  int i = 0;
  for (auto& it : notes) {
    idxOfNote[it] = i;
    i++;
  }
  for (int i = 0; i < 14; i++) {
    int mask = 0;
    for (auto& b : buttons[i]) {
      mask |= (1 << (b - 1));
    }
    bitmask[i] = mask;
  }
}

void countBits(int n, vector<int>& ans) {
  int ctr = 0;
  while (n > 0) {
    if (1 & n) ans[ctr]++;
    n = n >> 1;
    ctr++;
  }
}

void solution() {
  string str;
  vector<int> ans(10, 0);
  getline(cin, str);
  int currMask = 0;
  for (auto& it : str) {
    int buttonsToPress = bitmask[idxOfNote[it]] & ~(currMask);
    countBits(buttonsToPress, ans);
    currMask = bitmask[idxOfNote[it]];
  }
  for (int i = 0; i < 9; i++) cout << ans[i] << ' ';
  cout << ans[9] << endl;
}

int main() {
  init();

  int n;

  cin >> n;
  cin.ignore(100, '\n');

  while (n--) {
    solution();
  }

  return 0;
}