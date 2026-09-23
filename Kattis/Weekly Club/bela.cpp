#include <bits/stdc++.h>
using namespace std;

int table[2][8] = {{11, 4, 3, 20, 10, 14, 0, 0}, {11, 4, 3, 2, 10, 0, 0, 0}};
string cards = "AKQJT987";
unordered_map<char, int> cardToIdx;

void setupIdx() {
  int ctr = 0;
  for (auto& it : cards) {
    cardToIdx[it] = ctr;
    ctr++;
  }
}
int main() {
  setupIdx();
  int n;
  char suit, cardSuit, card;
  cin >> n >> suit;
  n *= 4;
  int ans = 0;
  int isDominant = 0;
  while (n--) {
    cin >> card >> cardSuit;
    isDominant = (cardSuit == suit);
    ans += table[!isDominant][cardToIdx[card]];
    cerr << table[!isDominant][cardToIdx[card]] << ' ' << isDominant << endl;
  }
  cout << ans << endl;
}