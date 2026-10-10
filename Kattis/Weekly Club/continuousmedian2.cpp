#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solution() {
  int n;
  priority_queue<int> maxQ;
  priority_queue<int, vector<int>, greater<int>> minQ;
  int64_t total = 0;
  cin >> n;
  while (n--) {
    int curr;
    cin >> curr;
    if (minQ.size() > 0) {
      if (minQ.top() < curr) {
        minQ.push(curr);
      } else
        maxQ.push(curr);
    } else
      minQ.push(curr);

    if (minQ.size() - 2 == maxQ.size()) {
      int temp = minQ.top();
      minQ.pop();
      maxQ.push(temp);
    } else if (minQ.size() == maxQ.size() - 2) {
      int temp = maxQ.top();
      maxQ.pop();
      minQ.push(temp);
    } else if (minQ.size() < maxQ.size()) {
      int temp = maxQ.top();
      maxQ.pop();
      minQ.push(temp);
    }

    if ((maxQ.size() + minQ.size()) % 2) {
      total += minQ.top();
    } else {
      int64_t temp = maxQ.top();
      temp = temp + (minQ.top() - temp) / 2;
      total += temp;
    }
  }
  cout << total << endl;
}

int main() {
  fastIO();
  int n;
  cin >> n;
  while (n--) {
    solution();
  }
  return 0;
}