#include "iostream"
#include "vector"
using namespace std;

struct PlantedTree {
  int row;
  int col;
  int n;
  PlantedTree(int x, int y, int n)
    : row(x), col(y), n(n) {}
};

vector<PlantedTree*> planted;

int main() {
  // r = Row Size
  // c = Column Size
  int r, c, n;
  cin >> r >> c >> n;
  vector<vector<PlantedTree*>> planting_area(r, vector<PlantedTree*>(c)); // Creates a [RxC] 2d array of zeroes.
  
  for (int i = 0; i < n; i++) {
    int rk, ck;
    cin >> rk >> ck;
    planting_area[rk-1][ck-1] = new PlantedTree(rk, ck, i + 1);
    planted.push_back(planting_area[rk-1][ck-1]);
  }
  
  int candidate = 0;
  int max_trees = 0;

  for (uint t = 0; t < planted.size(); t++) {
    PlantedTree *tree = planted[t];
    int found = 1;
    // Go Left
    if (tree->col > 1) {
      for (int i = (tree->col - 2); i >= 0; i--) {
        if (planting_area[tree->row - 1][i] != nullptr) {
          found++;
        }
      }
    }
    // Go Right
    if (tree->col < c) {
      for (int i = (tree->col); i < c; i++) {
        if (planting_area[tree->row - 1][i] != nullptr) { 
          found++;
        }
      }
    }
    // Go Up
    if (tree->row > 1) {
      for (int i = (tree->row - 2); i >= 0; i--) {
        if (planting_area[i][tree->col - 1] != nullptr) {
          found++;
        }
      }
    }
    // Go Down
    if (tree->row < r) {
      for (int i = (tree->row); i < r; i++) {
        if (planting_area[i][tree->col - 1] != nullptr) {
          found++;
        }
      }
    }
    if (found > max_trees) {
      max_trees = found;
      candidate = tree->n;
    }
  }
  cout << candidate << " " << max_trees << endl;
}
