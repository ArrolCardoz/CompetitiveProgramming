#include <bits/stdc++.h>
using namespace std;
void checkDistance(queue<long long> nums, vector<long long>& distance,
                   set<long long>& validSpeed) {
  int num1 = nums.front();
  nums.pop();
  int num2 = nums.front();
  int gotAns = 1;
  nums.pop();
  int n = 1;
  int speed = (num2 - num1) / distance[0];
  //   cout << num1 << ' ' << num2 << endl;
  if (nums.empty()) {
    validSpeed.insert(num2 - num1);
    return;
  }
  while (!nums.empty()) {
    int num = nums.front();
    nums.pop();
    int diff = num - num2;
    // cout << "((" << num2 << '-' << num << ")" << '/' << speed
    //      << "!=" << distance[n] << ")" << endl;
    // cout << diff << '/' << speed << '=' << distance[n] << endl;
    // cout << (diff) / speed << '=' << distance[n] << endl;

    if ((diff) / speed != distance[n]) {
      gotAns = 0;
      break;
    }
    num2 = num;
    n++;
  }
  if (gotAns) {
    validSpeed.insert(speed);
  }
}

int main() {
  long long n, m;
  cin >> m >> n;
  vector<long long> distance(m - 1);
  set<long long> validSpeed;
  long long ans = 0;
  queue<long long> q;
  long long num1, num2;
  cin >> num1;
  for (auto& it : distance) {
    cin >> num2;
    it = num2 - num1;
    // cout << it << endl;
    num1 = num2;
  }
  for (int i = 0; i < m; i++) {
    long long num;
    cin >> num;
    q.push(num);
  }
  for (int i = 0; i < n - m; i++) {
    checkDistance(q, distance, validSpeed);
    q.pop();
    int num;
    cin >> num;
    q.push(num);
  }
  checkDistance(q, distance, validSpeed);

  cout << validSpeed.size() << endl;
  for (auto& a : validSpeed) cout << a << ' ';
  cout << endl;
  return 0;
}