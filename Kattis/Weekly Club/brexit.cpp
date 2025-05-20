#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int, int>& initalRelation,
         unordered_map<int, int>& currentRelation,
         unordered_map<int, int>& checkCountryLeft,

         unordered_map<int, vector<int>>& adjList, int leave,
         queue<int>& countriesLeft) {
  for (auto& relation : adjList[leave]) {
    currentRelation[relation]++;
    if (currentRelation[relation] * 2 >= initalRelation[relation] &&
        !checkCountryLeft[relation]) {
      countriesLeft.push(relation);
      checkCountryLeft[relation] = 1;
    }
  }
}

int main() {
  int numCountries, numRelation, you, leave;
  unordered_map<int, int> initalRelation, currentRelation, checkCountryLeft;
  unordered_map<int, vector<int>> adjList;

  cin >> numCountries >> numRelation >> you >> leave;
  while (numRelation--) {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
    initalRelation[a]++;
    initalRelation[b]++;
  }
  queue<int> countriesLeft;
  countriesLeft.push(leave);
  checkCountryLeft[leave] = 1;
  while (!countriesLeft.empty()) {
    int a = countriesLeft.front();
    // cout << "LEAVE " << a << endl;
    countriesLeft.pop();
    if (a == you) {
      cout << "leave" << endl;
      return 0;
    }
    dfs(initalRelation, currentRelation, checkCountryLeft, adjList, a,
        countriesLeft);
  }
  cout << "stay" << endl;
  return 0;
}