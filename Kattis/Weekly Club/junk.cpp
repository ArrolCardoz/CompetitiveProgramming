#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct vec {
  ll x, y, z;
};

void solution() {
  vec a, av, b, bv, r, v;
  ll r1, r2;
  cin >> a.x >> a.y >> a.z >> r1 >> av.x >> av.y >> av.z;
  cin >> b.x >> b.y >> b.z >> r2 >> bv.x >> bv.y >> bv.z;
  // relative pos and velocity because its easier to compute distance
  // towards (0,0,0)
  r.x = a.x - b.x;
  r.y = a.y - b.y;
  r.z = a.z - b.z;
  v.x = av.x - bv.x;
  v.y = av.y - bv.y;
  v.z = av.z - bv.z;

  // find discriminant to see if it intersects the line
  // r + tv <= R
  // distance formula
  // r^2+ tv^2 <= R^2 -- pythagorean thm --- sqr both the sides
  ll R = r1 + r2;  // radius
  ll A = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
  ll B = 2 * (r.x * v.x + r.y * v.y + r.z * v.z);
  ll C = (r.x * r.x) + (r.y * r.y) + (r.z * r.z) - (R * R);
  if (A == 0) {
    cout << "No collision" << endl;
    return;
  }
  float dis = (B * B - 4 * A * C);
  if (dis < 0) {
    cout << "No collision" << endl;

    return;
  }
  dis = sqrt(dis);
  float d1 = (-B + dis) / (2 * A);
  float d2 = (-B - dis) / (2 * A);

  float ans = min(d1, d2);

  if (ans <= 0) {
    cout << "No collision" << endl;
  } else
    cout << fixed << setprecision(5) << ans << endl;
}

int main() {
  int n;
  cin >> n;
  while (n--) solution();
  return 0;
}