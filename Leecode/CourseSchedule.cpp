#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> inDegree(numCourses, 0);
  vector<vector<int>> adjacenyList(numCourses);
  for (int i = 0; i < prerequisites.size(); i++) {
    adjacenyList[prerequisites[i][1]].push_back(prerequisites[i][0]);
    inDegree[prerequisites[i][0]]++;
  }

  queue<int> que;
  for (int i = 0; i < inDegree.size(); i++) {
    if (inDegree[i] == 0) {
      que.push(i);
      inDegree[i]--;
    }
  }

  while (!que.empty()) {
    int top = que.front();
    que.pop();
    for (int i = 0; i < adjacenyList[top].size(); i++) {
      inDegree[adjacenyList[top][i]]--;
    }
    for (int i = 0; i < inDegree.size(); i++)
      if (inDegree[i] == 0) {
        que.push(i);
        inDegree[i]--;
      }
  }
  int maxDegree = 0;
  for (int i = 0; i < inDegree.size(); i++) {
    maxDegree = max(inDegree[i], maxDegree);
  }
  if (maxDegree == 0) return true;
  return false;
}