#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pairint;

char grid[25][25];
char A, B;
pairint coords;
int m, n;

int dfs(int x, int y) {
  coords = pairint(x, y);
  stack<pairint> visited;
  visited.push(coords);
  int count = 0;
  grid[x][y] = B;
  
  while(!visited.empty()) {  
    coords = visited.top();
    visited.top();
    x = coords.first;
    y = coords.second;
    count++;

    if (grid[x-1][y] == A && x > 0) { // Go up.
      coords = pairint(x-1, y);
      visited.push(coords);
      grid[x-1][y] = B;
    }

    if (grid[x+1][y] == A && x < m) { // Go down.
      coords = pairint(x+1, y);
      visited.push(coords);
      grid[x+1][y] = B;
    }

    if (grid[x][y-1] == A && y > 0) { // Go left.
      coords = pairint(x, y-1);
      visited.push(coords);
      grid[x][y-1] = B;
    }

    if (grid[x][y+1] == A && y < n) { // Go right.
      coords = pairint(x, y+1);
      visited.push(coords);
      grid[x][y+1] = B;
    }

    if (grid[x][n] == A && y == 0) { // Go to last col of row.
      coords = pairint(x, n);
      visited.push(coords);
      grid[x][n] = B;
    }

    if (grid[x][0] == A && y == n) { // Go to first col of row.
      coords = pairint(x, 0);
      visited.push(coords);
      grid[x][0] = B;
    }
  }
    return count;
}

int main() {
  while(cin >> m >> n) {
    m--; n--;
    for (int i = 0; i <= m; i++) {
      cin >> grid[i];
    }
    int x, y;
    cin >> x >> y;
    A = grid[x][y];
    if (A == 'l') B = 'w'; else B = 'l';
    dfs(x, y);
    int max = 0;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        if (grid[i][j] == A) {
          int count = dfs(i, j);
          if (max < count) max = count;
        }
      }
    }
    cout << max << endl;
  }
}
