#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100010;
const int MAX_M = 200010;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj_nodes[MAX_N];
  bool seen[MAX_N];
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--; // make it zero-based

    adj_nodes[u].push_back(v);
    adj_nodes[v].push_back(u);
  }
}
