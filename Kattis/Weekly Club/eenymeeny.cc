#include <bits/stdc++.h>
using namespace std;

int main() {
  // rhyme input
  string sentence;
  int lengthStr = 0;
  getline(cin, sentence);
  stringstream ss(sentence);
  while (ss >> sentence) {
    lengthStr++;
  }
  // name input
  int n;
  cin >> n;
  vector<string> people(n);
  for (auto& it : people) cin >> it;
  queue<string> t1, t2;
  int ctr = 0, ptr = -1;
  bool flag = true;
  // Since there are only 100 people we can afford to remove the names from
  // the list instead of keeping track of flags
  while (ctr != n) {
    ptr = (ptr + lengthStr) % people.size();

    if (flag)
      t1.push(people[ptr]);
    else
      t2.push(people[ptr]);
    cerr << people[ptr] << endl;
    people.erase(people.begin() + ptr);
    ptr--;

    // cerr << people[ptr] << endl;
    // for (auto& it : people) cerr << it << ' ';
    // cerr << endl;
    ctr++;
    flag = !flag;
  }

  // Output
  cout << t1.size() << endl;
  while (!t1.empty()) {
    cout << t1.front() << endl;
    t1.pop();
  }
  cout << t2.size() << endl;
  while (!t2.empty()) {
    cout << t2.front() << endl;
    t2.pop();
  }
  return 0;
}