#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> personID = {
    {"alice", 0}, {"bob", 1}, {"charlie", 2}};
unordered_map<int, string> personIDtoName = {
    {0, "alice"}, {1, "bob"}, {2, "charlie"}};
unordered_map<string, int> gameID = {
    {"golf", 1}, {"hockey", 2}, {"fishing", 0}};
unordered_map<int, set<int>> personInv = {{0, {0}}, {1, {1}}, {2, {2}}};

int main() {
  int n;
  cin >> n;
  while (n--) {
    // cerr << n << endl;
    string name, f1, f2, f3, game;
    cin >> name >> f1 >> f2 >> f3 >> game;
    // cerr << name << f1 << f2 << f3 << game << endl;
    int pId = personID[name], gId = gameID[game];
    int size = personInv[pId].size();
    personInv[pId].insert(gId);
    if (personInv[pId].size() == size) {
      cout << name << " already has " << game << endl;
    } else {
      for (auto& [a, b] : personInv) {
        if (a == pId) continue;
        if (b.find(gId) != b.end()) {
          b.erase(gId);
          cout << name << " borrows " << game << " from " << personIDtoName[a]
               << endl;
        }
      }
    }
  }
  return 0;
}
