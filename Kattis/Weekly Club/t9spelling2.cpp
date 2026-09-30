#include <bits/stdc++.h>
using namespace std;

// I used a vector of strings(keys) to initilize mapping unordered map
// Where each index is the button + 2 and the character index+1 represents
// how many times the button need to be pressed to get the character
// I  stored this in an unordered_map, I could have used an array/vector of size
// 26 with c - 'a' for this problem but since there are 100 test cases and 1000
// max string length I used a map because its easier to type.
// the maps key is char and stores a pair of int. Where the first represents how
// many times to press the button and second represents the button to be pressed
//-------------------------------------------------------------------------
// Solution
// The solution itself is straight foward where we loop through the string and
// use "mapping" to get the answer, there are few cases we need to handle where
// print '  ' if the buttons repeat.
// and
//' ' is button 0 which needs to be added in the "mapping" map

const vector<string> key = {"abc", "def",  "ghi", "jkl",
                            "mno", "pqrs", "tuv", "wxyz"};

unordered_map<char, pair<int, int>> mapping;

void setup() {
  int idx = 2;
  for (auto& it : key) {
    int ctr = 1;
    for (auto& i : it) {
      mapping[i] = {ctr, idx};
      ctr++;
    }
    idx++;
  }
  mapping[' '] = {1, 0};
}

void solution() {
  string str;
  getline(cin, str);
  // cerr << str << endl;
  int prevButton = -1;
  int currButton = 0, repeatButton = 0;
  for (auto& it : str) {
    repeatButton = mapping[it].first;
    currButton = mapping[it].second;
    // cerr << prevButton << ' ' << currButton << endl;
    if (currButton == prevButton) cout << ' ';

    while (repeatButton--) {
      cout << currButton;
    }
    prevButton = currButton;
  }
  cout << endl;
}

int main() {
  setup();
  int n, ctr = 1;

  cin >> n;
  cin.ignore(100, '\n');
  while (n--) {
    cout << "Case #" << ctr << ": ";
    solution();
    ctr++;
  }
  return 0;
}
