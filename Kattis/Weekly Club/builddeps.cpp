#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<string, pair<vector<string>, int>> &dependencies,
         queue<string> &change) {
  string c = change.front();
  cout << c << endl;
  change.pop();
  for (auto &s : dependencies[c].first) {
    if (!dependencies[s].second) {
      dependencies[s].second = 1;

      change.push(s);
    }
  }
  if (!change.empty()) dfs(dependencies, change);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  unordered_map<string, pair<vector<string>, int>> dependencies;
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    stringstream LINE(line);
    string key, parent;
    LINE >> key;
    key.pop_back();
    dependencies[key].second = 0;
    while (LINE >> parent) {
      dependencies[parent].first.push_back(key);
    }
  }
  queue<string> change;
  string input;
  cin >> input;
  change.push(input);
  dfs(dependencies, change);
  return 0;
}