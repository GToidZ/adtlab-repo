#include <iostream>

using namespace std;

int wall[15][15];

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    // Create wall
    for (int i = 1; i <= 9; i += 2) {
      for (int j = 1; j <= i; j += 2) {
        cin >> wall[i][j];
      }
    }
    for (int i = 3; i <= 9; i += 2) {
      for (int j = 2; j <= i; j += 2) {
        int a = wall[i][j-1];
        int b = wall[i][j+1];
        int c = wall[i-2][j-1];
        wall[i][j] = (c-b-a)/2;
        wall[i-1][j-1] = (c-b+a)/2;
        wall[i-1][j] = (c+b-a)/2;
      }
    }
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= i; j++) {
        char end;
        if (j == i) end = '\n';
        else end = ' ';
        cout << wall[i][j] << end;
      }
    }
  }
}
