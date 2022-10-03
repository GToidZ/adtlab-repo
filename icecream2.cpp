#include <iostream>
using namespace std;

struct Customer {
  int id;
  int flavor;
  Customer(int id, int f)
    : id(id), flavor(f) {}
};

typedef Customer ValueType;
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
  int sales[20] = {};

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int t;

    cin >> t;
    if (t == 1) {
      int n;
      cin >> n;
      for (int j = 0; j < n; j++) {
        int cid, flavor;
        cin >> cid >> flavor;
        Customer *customer = new Customer(cid, flavor);
        append(front, rear, *customer);
      }
    } else {
      Customer customer = extract(front, rear);
      cout << customer.id << endl;
      sales[customer.flavor - 1] += 1;
    }
  }

  int remain = 0;
  ListNode *cursor = front;
  while(cursor!=nullptr) {
    remain++;
    cursor = cursor->next;
  }
  cout << remain << endl;

  for (int i = 0; i < 20; i++) {
    if ((i + 1) >= 20) {
      cout << sales[i] << endl;
    } else {
      cout << sales[i] << " ";
    }
  }
}
