#include <bits/stdc++.h>
using namespace std;

int main() {
  string sentence;
  int lengthStr = 0;
  getline(cin, sentence);
  stringstream ss(sentence);
  while (ss >> sentence) {
    lengthStr++;
  }
  int n;
  cin >> n;
  vector<string> people(n);
  for (auto& it : people) cin >> it;
  queue<string> t1, t2;
  int ctr = 0, ptr = -1;
  bool flag = true;

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

    for (auto& it : people) cerr << it << ' ';
    cerr << endl;
    ctr++;
    flag = !flag;
  }
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