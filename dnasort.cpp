#include <iostream>
#include <algorithm>

using namespace std;

struct DNA {
  string val;
  int inv, id;
}dna[101];

bool compare(DNA first, DNA second) {
  if(first.inv == second.inv) return first.id < second.id;
  return first.inv < second.inv;
}

int get_inv(int n, string s) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] > s[j]) count++;
    }
  }
  return count;
}

int main() {
  int M;
  cin >> M;
  while (M--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> dna[i].val;
      dna[i].inv = get_inv(n, dna[i].val);
      dna[i].id = i;
    }
    stable_sort(dna+1, dna+1+m, compare);
    for (int i = 1; i <= m; i++) {
      cout << dna[i].val << endl;
    }
    if (M) cout << endl;
  }
}
