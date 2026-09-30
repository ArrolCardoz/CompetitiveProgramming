#include <bits/stdc++.h>
using namespace std;
// "table" is a 2d array where first row is the dominant and second is non
// dominant
// in order to look up the table with the card it represents we need to convert
// the cards to index
// since the cards do not have any perticular order we cannot use an array so we
// have to use a mask
// and since N is atmost 100 so 400 in total we can afford to initilize
// "cardToIdx" in the problem itself instead of manually typing it
//"cards" string is the order of the give table and it initilized in setupIdx
//function.
// ------------------------------------------------------------------------------------
// solution
// the remaining solution itself is straight foward which is a table lookup
// while checking if the card is dominant or not
const int table[2][8] = {{11, 4, 3, 20, 10, 14, 0, 0},
                         {11, 4, 3, 2, 10, 0, 0, 0}};
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