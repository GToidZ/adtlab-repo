#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef queue<int> QueueInt;

int graph[210][210];
int visited[210];
bool flag;

void bfs(int n) {
  visited[0] = 0;
  QueueInt q;
  q.push(0);
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    for(int i = 0; i < n; i++) {
      if (i != tmp && graph[tmp][i] == 1) {
        if (visited[i] == -1) {
          visited[i] = 1 - visited[tmp];
          q.push(i);
        } else if (visited[i] == visited[tmp]) {
          flag = false;
          return;
        }
      }
    }
  }
}

int main() {
  int lines;
  int n;
  while (cin >> n && n) {
    cin >> lines;
    memset(graph, 0, sizeof(graph)); memset(visited, -1, sizeof(visited));
    int a, b;
    while(lines--) {
      cin >> a >> b;
      graph[a][b] = graph[b][a] = 1;
    }
    flag = true;
    bfs(n);
    if (flag) cout << "BICOLORABLE." << endl;
    else cout << "NOT BICOLORABLE." << endl;
  }
}
