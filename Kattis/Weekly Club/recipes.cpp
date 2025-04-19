#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
  // process input
  float numIng, numPortion, desirePortion;
  map<int, pair<float, float>> weightPercentage;
  float weight, percentage;
  int mainIng;
  string name;
  cin >> numIng >> numPortion >> desirePortion;
  vector<string> ingName(numIng);
  for (int i = 0; i < numIng; i++) {
    cin >> name >> weight >> percentage;
    ingName[i] = name;
    weightPercentage[i] = make_pair(weight, percentage);
    if (percentage == 100) mainIng = i;
  }
  // calculate scaling factor
  float scalingFactor = desirePortion / numPortion;
  //   cout << desirePortion << '/' << numPortion << endl;
  //   cout << scalingFactor << "===============" << endl;
  // process main ingredient
  float finalMain = weightPercentage[mainIng].first * scalingFactor;

  // process the remaining ingredients
  cout << "Recipe # " << n << endl;
  for (int i = 0; i < numIng; i++)
    cout << ingName[i] << ' ' << setprecision(1) << fixed
         << finalMain * (weightPercentage[i].second / 100) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solution(i);
    for (int i = 0; i < 40; i++) cout << '-';
    cout << endl;
  }
  return 0;
}