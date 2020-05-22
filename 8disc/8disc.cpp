

//find time complexity
void foo(int n) {
  int i, j, k = 0;
  for (i = n / 2; i <= n; i++) { //n
      for (j = 2; j <= n; j = j * 2) {//logn  n = 128; 2 4 8 16 32 64 128
          k = k + n / 2;
      }
  }
}







//nlogn


class node
{
  public:
  int getNchildren() { return numChild; }
  int getValue() { }
  node* getChild(int place) { }

  private:
  int value;
  node* children;
  int numChild;
  int size;

};


int find(node* root, int k) {
  if (root == nullptr)
    return -1;
  if (root->getValue() == k) {
    int sum = 0;
    for (int i = 0; i < root->getNchildren(); i++) {
      sum+=root->getChild(i)->getValue();
    }
    return sum;
  } else {
    int res = -1;
    for (int i = 0; i < root->getNchildren(); i++) {
      int temp = find(root->getChild(i), k);
      if (temp > res)
        res = temp;
    }
    return res;
  }
}

//nlogn
