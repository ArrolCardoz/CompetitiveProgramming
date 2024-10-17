// 11
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int start = 0;
  int end = height.size() - 1;
  int ans = 0;
  while (start < end) {
    int minHeight = min(height[start], height[end]);
    int length = end - start;
    ans = max(ans, minHeight * length);
    if (height[start] > height[end])
      end--;
    else
      start++;
  }
  return ans;
}

int main() {
  vector<int> height = {1, 1};
  cout << maxArea(height) << endl;
  return 0;
}