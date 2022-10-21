#include <iostream>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void inorder(TreeNode* r)
{
  if(!r) {
    return;
  }
  inorder(r->left);
  cout << r->val << endl;
  if(r != NULL) inorder(r->right);
}

void insert(TreeNode*& r, valueType x) {
  if(!r) {
    r = new TreeNode(x);
  } else if(x < r->val) {
    insert(r->left, x);
  } else if(x > r->val) {
    insert(r->right, x);
  }
}

TreeNode* find(TreeNode* r, valueType x) {
  if(!r) {
    return NULL;
  }
  else if(x < r->val) {
    return find(r->left, x);
  }
  else if(x > r->val) {
    return find(r->right, x);
  }
  return r;
}

int main()
{
  TreeNode* root;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k, x;
    cin >> k >> x;
    if (k == 1) {
      if (!root) {
        root = new TreeNode(x);
      } else {
        insert(root, x);
      }
    }
    if (k == 2) {
      if (!root) { 
        cout << 0 << endl;
      } else {
        cout << (find(root, x) ? 1 : 0) << endl;
      }
    }
  }
}
