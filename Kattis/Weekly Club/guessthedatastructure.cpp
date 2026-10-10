#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

void solution(int n) {
  int caseNum, num;
  priority_queue<int> pq;
  stack<int> s;
  queue<int> q;
  int flags[3] = {true, true, true};
  string name[3] = {"priority queue", "stack", "queue"};

  while (n--) {
    cin >> caseNum >> num;
    if (caseNum == 1) {
      pq.push(num);
      s.push(num);
      q.push(num);
    } else {
      if (pq.empty()) {
        flags[0] &= false;
        flags[1] &= false;
        flags[2] &= false;
        continue;
      }

      flags[0] &= num == pq.top();
      flags[1] &= num == s.top();
      flags[2] &= num == q.front();
      pq.pop();
      s.pop();
      q.pop();
    }
  }
  if (count(flags, flags + 3, true) == 0)
    cout << "impossible" << endl;
  else if (count(flags, flags + 3, true) > 1)
    cout << "not sure" << endl;
  else {
    for (int i = 0; i < 3; i++) {
      if (flags[i]) {
        cout << name[i] << endl;
        break;
      }
    }
  }
}
int main() {
  fastIO();
  int n;
  while (cin >> n) solution(n);
  return 0;
}