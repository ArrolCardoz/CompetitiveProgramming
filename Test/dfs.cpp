#include <iostream>
#include <vector>
using namespace std;
vector<int> nums[10000];
bool visit[10000];

void dfs(int vertex) {
  visit[vertex] = true;
  cout << vertex << " ";
  for (auto &it : nums[vertex]) {
    if (visit[it]) continue;
    dfs(it);
  }
}

int main() {
  int v, m;
  cin >> v >> m;
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    nums[v1].push_back(v2);
    nums[v2].push_back(v1);
  }
  dfs(1);
}