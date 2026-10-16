#include <bits/stdc++.h>
using namespace std;
#define LSOne(s) ((s) & -(s))
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastIO();
  string str = "";
  int A[10][10];
  stack<int> s;
  int startCtr = 0, endCtr = 0, ctr = 0;
  char c;
  while (cin >> c) {
    if (c == '(') {
      s.push(ctr);
      startCtr++;
    } else if (c == ')') {
      A[endCtr][0] = s.top();
      A[endCtr][1] = ctr;
      s.pop();
      endCtr++;
    }
    ctr++;
    str += c;
  }

  set<string> ans;
  for (int i = 1; i < (1 << (startCtr)); i++) {
    int mask = i;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (mask) {
      int pow_two_j = LSOne(mask);
      int j = __builtin_ctz(pow_two_j);
      mask -= pow_two_j;
      pq.push(A[j][0]);

      pq.push(A[j][1]);
    }
    string temp = "";
    for (int i = 0; i < (int)str.size(); i++) {
      if ((!pq.empty() && pq.top() != i) || pq.empty())
        temp += str[i];
      else {
        pq.pop();
      }
    }
    ans.insert(temp);
  }
  for (auto& it : ans) cout << it << '\n';
  return 0;
}