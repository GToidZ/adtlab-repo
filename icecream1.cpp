#include <iostream>
using namespace std;

typedef int ValueType;
struct ListNode {
  ValueType val;
  ListNode* next;

  ListNode(ValueType v, ListNode* nxt=0)
    : val(v), next(nxt) {}
};

ListNode* front = nullptr;
ListNode* rear = nullptr;

void append(ListNode*& front, ListNode*& rear, ValueType x)
{
  ListNode* n = new ListNode(x);
  if (rear != nullptr) {
    rear->next = n;
    rear = n;
  } else {
    front = rear = n;
  }
}

ValueType extract(ListNode*& front, ListNode*& rear)
{
  ValueType v = front->val;

  ListNode* new_front = front->next;
  delete front;
  front = new_front;
  if (front == nullptr) {
    rear = nullptr;
  }
  return v;
}

int main()
{
  int m;

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int t;

    cin >> t;
    if (t == 1) {
      int n;
      cin >> n;
      for (int j = 0; j < n; j++) {
        int cid;
        cin >> cid;
        append(front, rear, cid);
      }
    } else {
      cout << extract(front, rear) << endl;
    }
  }

  int remain = 0;
  ListNode *cursor = front;
  while(cursor!=nullptr) {
    remain++;
    cursor = cursor->next;
  }
  cout << remain << endl;
}
