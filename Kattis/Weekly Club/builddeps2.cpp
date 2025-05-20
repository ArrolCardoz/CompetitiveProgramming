#include <bits/stdc++.h>
using namespace std;

void findAffectedFiles(unordered_map<string, vector<string>> &revAdj,
                       unordered_set<string> &affectedFile, string file,
                       unordered_map<string, int> &visited) {
  affectedFile.insert(file);
  visited[file] = 1;
  for (auto &f : revAdj[file]) {
    if (!visited[f]) findAffectedFiles(revAdj, affectedFile, f, visited);
  }
}

void topoSort(unordered_map<string, vector<string>> &adjList,
              unordered_map<string, int> &visited,
              unordered_set<string> &affectedFile, vector<string> &ans,
              string file) {
  visited[file] = 1;
  for (auto &f : adjList[file]) {
    if (!visited[f] && affectedFile.find(f) != affectedFile.end()) {
      topoSort(adjList, visited, affectedFile, ans, f);
    }
  }
  ans.push_back(file);
}

int main() {
  int n;
  cin >> n;
  cin.ignore();
  unordered_map<string, vector<string>> adjList;
  unordered_map<string, vector<string>> revAdj;
  unordered_map<string, int> visited, visited2;
  unordered_set<string> affectedFiles;
  vector<string> ans;
  string change;
  string line;
  string key, child;

  while (n--) {
    getline(cin, line);
    stringstream LINE(line);

    LINE >> key;
    key.pop_back();

    while (LINE >> child) {
      visited[key] = 0;
      adjList[key].push_back(child);
      revAdj[child].push_back(key);
    }
  }
  cin >> change;
  findAffectedFiles(revAdj, affectedFiles, change, visited);

  for (auto &af : affectedFiles) {
    if (!visited2[af]) topoSort(adjList, visited2, affectedFiles, ans, af);
  }

  // reverse(ans.begin(), ans.end());
  for (auto &a : ans) cout << a << endl;
  return 0;
}