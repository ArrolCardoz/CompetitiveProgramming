#include <bits/stdc++.h>
using namespace std;

void printSideFrame(int framethickness, char material) {
  for (int i = 0; i < framethickness; i++) {
    cout << material;
  }
}

int main() {
  string art;
  char material;
  int frameThickness = 0, gap = 0;
  cin >> art >> material >> frameThickness >> gap;
  //   int height = 1 + frameThickness + gap;
  int width = frameThickness + gap + art.size() + gap + frameThickness;
  int gapWithoutArtWidth = art.size() + gap + gap;
  // top frame
  for (int i = 0; i < frameThickness; i++) {
    printSideFrame(width, material);
    cout << endl;
  }
  // top gap
  for (int i = 0; i < gap; i++) {
    printSideFrame(frameThickness, material);
    printSideFrame(gapWithoutArtWidth, ' ');
    printSideFrame(frameThickness, material);
    cout << endl;
  }
  // art
  printSideFrame(frameThickness, material);
  printSideFrame(gap, ' ');
  cout << art;
  printSideFrame(gap, ' ');
  printSideFrame(frameThickness, material);
  cout << endl;

  // bottom gap
  for (int i = 0; i < gap; i++) {
    printSideFrame(frameThickness, material);
    printSideFrame(gapWithoutArtWidth, ' ');
    printSideFrame(frameThickness, material);
    cout << endl;
  }
  // bottom frame
  for (int i = 0; i < frameThickness; i++) {
    printSideFrame(width, material);
    cout << endl;
  }
  return 0;
}