#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long dividePlayers(vector<int>& skill) {
  long long ans = 0;
  sort(skill.begin(), skill.end());
  int lowerBound = 0;
  int upperBound = skill.size() - 1;
  if (upperBound % 2 == 0) return -1;
  long long addSkill = skill[lowerBound] + skill[upperBound];
  while (lowerBound < upperBound) {
    int temp = skill[lowerBound] + skill[upperBound];
    if (temp != addSkill) return -1;
    ans += (skill[lowerBound] * skill[upperBound]);
    lowerBound++;
    upperBound--;
  }

  return ans;
}

int main() {
  vector<int> skill = {1, 1, 2, 3};
  cout << dividePlayers(skill);
  return 0;
}