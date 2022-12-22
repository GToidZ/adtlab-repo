#include <iostream>

using namespace std;

int main() {
  int k = 1;
  while (1) {
    cin >> k;
    if (!k) break;
    int dX, dY;
    cin >> dX >> dY;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      if (x == dX || y == dY) cout << "divisa" << endl;
      if (x > dX && y > dY) cout << "NE" << endl;
      if (x < dX && y > dY) cout << "NO" << endl;
      if (x < dX && y < dY) cout << "SO" << endl;
      if (x > dX && y < dY) cout << "SE" << endl;
    }
  }
}
