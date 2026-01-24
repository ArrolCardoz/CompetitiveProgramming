#include <bits/stdc++.h>
using namespace std;

void event(stack<string>& s, unordered_map<string, int>& idx) {
  // //cerr << "E" << endl;
  string str;
  cin >> str;
  idx[str] = s.size();
  s.push(str);
}

void dream(stack<string>& s, unordered_map<string, int>& idx) {
  // //cerr << "D" << endl;

  int n;
  cin >> n;
  // cerr << "REMOVE " << n << endl;
  while (n--) {
    // cerr << idx.size() << endl;

    string str = s.top();

    // cerr << str << endl;
    s.pop();
    idx.erase(str);
  }
  // cerr << idx.size() << endl;
  //  for (auto& [m, n] : idx) //cerr << "m,n " << m << ' ' << n << endl;
}

bool lookup(string str, unordered_map<string, int>& idx) {
  // //cerr << "L" << endl;

  if (idx.find(str) == idx.end()) {
    return false;
  }
  return true;
}

void scenario(stack<string>& s, unordered_map<string, int>& idx) {
  // //cerr << "S" << endl;

  int n;
  int lowerBound = 0, upperBound = INT_MAX;

  cin >> n;
  while (n--) {
    string input;
    cin >> input;
    if (input[0] == '!') {
      // not
      if (lookup(input.substr(1), idx)) {
        int id = idx[input.substr(1)];
        lowerBound = max(lowerBound, (int)s.size() - id);
      }
    } else {
      if (lookup(input, idx)) {
        int id = idx[input];
        upperBound = min(upperBound, (int)s.size() - id - 1);
      } else {
        upperBound = -1;
      }
    }
  }
  // for (auto& [m, n] : idx)  // cerr << "m,n " << m << ' ' << n << endl;

  if (lowerBound > upperBound)
    cout << "Plot Error" << endl;
  else if (lowerBound)
    cout << lowerBound << " Just A Dream" << endl;
  else
    cout << "Yes" << endl;
}

int main() {
  int n;
  stack<string> s;
  unordered_map<string, int> idx;
  char c;
  cin >> n;
  while (n--) {
    cin >> c;
    switch (c) {
      case 'E':
        event(s, idx);
        break;
      case 'D':
        dream(s, idx);
        break;
      case 'S':
        scenario(s, idx);
        break;
    }
  }
  return 0;
}