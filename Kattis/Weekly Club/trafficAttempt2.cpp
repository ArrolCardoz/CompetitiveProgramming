#include <bits/stdc++.h>
using namespace std;

const int MAXTIME = 4'000'001;

int currentTime[4'000'001] = {0};

int main() {
  int pos1, pos2;
  cin >> pos1 >> pos2;
  bool isStopped = true;
  int n;
  queue<int> q1, q2;
  cin >> n;

  // input
  while (n--) {
    int input;
    cin >> input;
    q1.push(input);
  }
  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    q2.push(input);
  }

  // simulate
  for (int i = 0; i < MAXTIME; i++) {
    if (!isStopped) pos1++;
    if (!q1.empty() && q1.front() == i) {
      isStopped = !isStopped;
      q1.pop();
    }
    currentTime[i] = pos1;
  }
  isStopped = true;

  for (int i = 0; i < MAXTIME; i++) {
    if (!isStopped) pos2++;
    if (!q2.empty() && q2.front() == i) {
      isStopped = !isStopped;
      q2.pop();
    }
    if (abs(pos2 - currentTime[i]) < 5) {
      cout << "bumper tap at time " << i;
      return 0;
    }
  }
  cout << "safe and sound" << endl;
  return 0;
}