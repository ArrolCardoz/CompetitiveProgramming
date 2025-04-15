#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Structure to store laser data
struct Laser {
  double x_intersection;
  string name;
};

// Comparator function for sorting by x-intersection
bool compare(const Laser &a, const Laser &b) {
  return a.x_intersection < b.x_intersection;
}

int main() {
  int n;
  cin >> n;

  vector<Laser> lasers;

  for (int i = 0; i < n; i++) {
    double x0, y0, m;
    string name;
    cin >> x0 >> y0 >> m >> name;

    if (m > 0) {  // Only consider lasers pointing upwards
      double x_intersection = x0 - (y0 / m);
      lasers.push_back({x_intersection, name});
    }
  }

  // Sort lasers by x-intersection
  sort(lasers.begin(), lasers.end(), compare);

  // Print the names in sorted order
  for (const auto &laser : lasers) {
    cout << laser.name << endl;
  }

  return 0;
}
