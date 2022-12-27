#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> edges(50010), sum(50010);
vector<bool> visited(50010);

int dfs(int start) {
  if (visited[start]) return 0;
  visited[start] = true;
  int total = 1;
  if (edges[start] != -1 && !visited[edges[start]]) {
    total = (1 + dfs(edges[start]));
    visited[edges[start]] = false;
  }
  return sum[start] = total;
}

int main() {
  int T, currcase = 0;
  cin >> T;
  while(T--) {
    ll N;
    cin >> N;
    edges.assign(N+5, -1);
    sum.assign(N+5, -1);
    visited.assign(N+5, false);
    for (int i = 0; i < N; i++) {
      int a;
      ll b;
      cin >> a >> b;
      edges[a] = b;
    }
    ll max = 0, selected = 0, temp;
    for (int i = 1; i <= N; i++) {
      temp = 0; // Reset temp
      visited[i-1] = false;
      if (sum[i] == -1) {
        temp = dfs(i);
      }
      if (temp > max) {
        selected = i;
        max = temp;
      }
    }
    cout << "Case " << ++currcase << ": " << selected << endl;
  }
}
