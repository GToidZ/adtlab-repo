#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


void topology_sort(
    vector<bool> &tasks, vector<vector<int>> &adj,
    vector<int> &order, int x)
{
  tasks[x] = true;

  for (int i = 0; i < adj[x].size(); ++i) {
    int inner = adj[x][i];
    if (!tasks[inner]) topology_sort(tasks, adj, order, inner);
  }

  order.push_back(x);
}

int main() {
  int n, m;
  while (cin >> n >> m, n || m) {
    vector<bool> tasks(110, false);
    vector<vector<int>> adj(110);
    vector<int> order;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
      if(!tasks[i]) topology_sort(tasks, adj, order, i);
    }
    /*for (int i = 0; i < order.size(); ++i) {
      cout << order[i] << " \n"[i == order.size() - 1];
    }*/
    copy(order.rbegin(), order.rend(), ostream_iterator<int>(cout, " "));
    cout << endl;
  }
}
