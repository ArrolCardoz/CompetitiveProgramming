#include <bits/stdc++.h>
using namespace std;

unordered_map<string, double> classIdx = {
    {"reppu", 3}, {"elddim", 2}, {"rewol", 1}};

bool customSort(pair<double, string>& a, pair<double, string>& b) {
  if (a.first > b.first)
    return true;
  else if (a.first < b.first)
    return false;
  else {
    return a.second < b.second;
  }
}

void solution() {
  int n;
  cin >> n;
  cin.ignore();

  vector<pair<double, string>> pq;
  while (n--) {
    string name, hierarchy, input, temp, line;
    double currMultiplyer = 1, curr = 0;

    getline(cin, line);

    stringstream ss(line);

    getline(ss, name, ':');
    ss >> hierarchy >> temp;
    // cerr << "EXTRACTED: " << name << " " << hierarchy << temp << endl;
    // cerr << hierarchy << endl;
    reverse(hierarchy.begin(), hierarchy.end());
    // cerr << hierarchy << endl;

    stringstream hss(hierarchy);
    int idx = 0;
    while (getline(hss, hierarchy, '-')) {
      //   cerr << hierarchy << endl;
      curr += classIdx[hierarchy] * currMultiplyer;
      currMultiplyer *= 0.1;
      idx++;
    }
    while (idx < 10) {
      curr += 2 * currMultiplyer;
      currMultiplyer *= 0.1;
      idx++;
    }

    pq.emplace_back(curr, name);
  }
  sort(pq.begin(), pq.end(), customSort);
  for (auto& it : pq) {
    cout << it.second << endl;
    // cerr << it.first << ' ' << it.second << endl;
  }
  for (int i = 0; i < 30; i++) cout << "=";
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}