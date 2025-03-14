#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int idx, int depth, int targetSum) {
  if (root[idx] == targetSum && idx >= root.size() / 2) return true;
  int newDepth = depth + 1;
  for (int i = 0; i < depth && idx < root.size(); i++) {
    idx++;
    dfs(root, idx, newDepth, targetSum);
  }
  return false;
}
bool hasPathSum(TreeNode *root, int targetSum) {
  int depth = 1;
  return dfs(root, 0, depth, targetSum);
}