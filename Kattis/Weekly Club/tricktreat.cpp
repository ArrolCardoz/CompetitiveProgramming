#include <bits/stdc++.h>
using namespace std;

double sumHypot(vector<pair<double, double>>& coords, double midpoint,
                double& sum) {
  for (auto& it : coords) {
    sum += hypot()
  }
}

int main() {
  vector<pair<double, double>> coords;
  int n;
  cin >> n;
  coords.reserve(n);
  double xMin = 300000, xMax = -200001;
  while (n--) {
    double x, y;
    cin >> x >> y;
    coords.emplace_back(x, y);
    xMax = max(xMax, x);
    xMin = min(xMin, x);
  }

  while ((xMax * 100000) != xMin * 100000) {
    double midpoint1 = (xMax - xMin) / 3, midpoint2;
    midpoint2 = midpoint2 * 2;
    double hypot1 = 0, hypot2 = 0;
  }
  return 0;
}