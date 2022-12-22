#include <iostream>

using namespace std;

int mat[101][101], dfsMat[101][101], grid;
bool flag;

void make_graph() {
  string str = "", tmp;
  for (int i = 0; i < grid; i++) {
    cin >> tmp;
    str += tmp;
  }
  int index = 0;
  for (int x = 0; x < grid; x++) {
    for (int y = 0; y < grid; y++) {
      mat[x][y] = str[index];
      if(mat[x][y] == 'x' || mat[x][y] == '@') dfsMat[x][y] = -1;
      else dfsMat[x][y] = 0;
      index++;
    }
  }
}

void dfs(int x, int y) {
  if (mat[x][y] == 'x') flag = true;
  dfsMat[x][y] = 1;
  int a = x, b = y;
    if (a - 1 >= 0 && dfsMat[a-1][b] == -1) {
        dfs(a-1, b);
    }
    if (a + 1 < grid && dfsMat[a+1][b] == -1) {
        dfs(a+1, b);
    }
    if (b - 1 >= 0 && dfsMat[a][b-1] == -1) {
        dfs(a, b-1);
    }
    if (b + 1 < grid && dfsMat[a][b+1] == -1) {
        dfs(a, b+1);
    }
}

int main() {
  int cases;
  cin >> cases;
  int curr = cases;
  while (curr--) {
    cin >> grid;
    make_graph();
    int ships = 0;
    for (int x = 0; x < grid; x++) {
      for (int y = 0; y < grid; y++) {
        if ((mat[x][y] == 'x' || mat[x][y] == '@') && dfsMat[x][y] == -1) {
          flag = false;
          dfs(x, y);
          if (flag) ships++;
        }
      }
    }
    cout << "Case " << cases-curr << ": " << ships << endl;
  }
}
