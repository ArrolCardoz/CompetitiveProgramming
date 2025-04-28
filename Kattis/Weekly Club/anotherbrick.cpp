#include <bits/stdc++.h>
using namespace std;

int main() {
  int layer, width, bricks, currentLayer = 0, layerDone = 0;
  cin >> layer >> width >> bricks;
  int b;
  for (int i = 0; i < bricks; i++) {
    if (layerDone == layer) {
      cout << "YES" << endl;
      return 0;
    }
    cin >> b;
    currentLayer += b;
    if (currentLayer == width) {
      layerDone++;
      currentLayer = 0;
    }
    if (currentLayer > width) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (layerDone == layer) {
    cout << "YES" << endl;
    return 0;
  } else
    cout << "NO" << endl;
  return 0;
  assert(false);
}