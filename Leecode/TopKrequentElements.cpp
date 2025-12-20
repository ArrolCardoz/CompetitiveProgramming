#include <bits/stdc++.h>
using namespace std;
// challenge don't sort
vector<int> topKFrequent(vector<int>& nums, int k) {
  vector<int> ans;
  unordered_map<int, int> total;
  priority_queue<pair<int, int> > pq;
  int ctr = 1;

  for (auto& it : nums) {
    total[it]++;
  }
  for (auto& [m, n] : nums) pq.push({n, m});

  for (int i = 0; i <= k; i++) {
    pair<int, int> onTop;
    pq.top();
    pq.pop();
    ans.push_back(onTop.second);
  }
  return ans;
}

vector<int> topKFrequent2(vector<int>& nums, int k) {
  vector<int> ans;
  map<int, int> total;
  priority_queue<pair<int, int> > pq;
  int ctr = 1;

  for (auto& it : nums) {
    total[it]++;
  }
  for (auto& [m, n] : nums) pq.push({n, m});

  for (int i = 0; i <= k; i++) {
    pair<int, int> onTop;
    pq.top();
    pq.pop();
    ans.push_back(onTop.second);
  }
  return ans;
}

int main() { return 0; }