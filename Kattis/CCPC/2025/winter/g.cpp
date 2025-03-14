#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<vector<int>> &pipes,
              vector<int> &poolContaminated) {
  //   cout << "PIPE" << n << endl;
  poolContaminated[n] = 0;
  //   for (auto &it : pipes[n]) cout << it << endl;

  for (int i = 0; i < pipes[n].size(); i++) {
    if (poolContaminated[pipes[n][i]] == 0) continue;
    poolContaminated[pipes[n][i]] = 0;
    // cout << "TEST" << pipes[n][i] << endl;
    solution(pipes[n][i], pipes, poolContaminated);
  }
  return;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> poolContaminated(n, 1);
  vector<int> people(n);
  vector<vector<int>> pipes(n);
  //   cout << n << m << k << endl;

  for (int i = 0; i < n; i++) {
    // cout << i << endl;
    int temp;
    cin >> temp;
    people[i] = temp;
  }

  for (int i = 0; i < m; i++) {
    // cout << i << ' ' << m << endl;
    int a, b;
    cin >> a >> b;
    pipes[a - 1].push_back(b - 1);
    pipes[b - 1].push_back(a - 1);
  }
 
  for (int i = 0; i < k; i++) {
    int temp;
    cin >> temp;
    solution(temp - 1, pipes, poolContaminated);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (poolContaminated[i] == 1) ans += people[i];
  }
  cout << ans << endl;
  return 0;
}