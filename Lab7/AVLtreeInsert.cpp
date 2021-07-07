#include <bits/stdc++.h>
using namespace std;
 
 
struct niceOutput {
    int data;
    int left;
    int right;
 
    niceOutput() = default;
 
    niceOutput(int data, int left, int right) : data{data}, left{left}, right{right} {}
};
 
 
struct AVLTree {
    struct node {
        int value;
        node *leftId;
        node *rightId;
        int height;
        node(): value{-1}, leftId{nullptr}, rightId{nullptr}, height{-1} {}
    };
    AVLTree(): root{nullptr}{}
    node *root;
 
 
    int height(node* x) {
        if (x == nullptr) return -1;
        if (x->height == -1) fixheight(x);
        return x->height;
    }
 
    int balance(node* x) {
        return height(x->rightId) - height(x->leftId);
    }
 
    void fixheight(node* x){
        x->height = max(height(x->leftId), height(x->rightId)) + 1;
    }
 
 
    node* smallLeftTurn(node* x) {
        node* y = x->rightId;
        x->rightId = y->leftId;
        y->leftId = x;
        fixheight(x);
        fixheight(y);
        return y;
    }
 
 
    node* smallRightTurn(node* x) {
        node* y = x->leftId;
        x->leftId = y->rightId;
        y->rightId = x;
        fixheight(x);
        fixheight(y);
        return y;
    }
 
    node* rebalance(node* x){
        fixheight(x);
      //  cout<<"debug: height of "<<x->value<< "after fix = "<<height(x)<<endl;
      //  cout<<"debug: balance of "<<x->value<< "after fix = "<<balance(x)<<endl;
        if(balance(x)==2)
        {
            if (balance(x->rightId) < 0)
                x->rightId = smallRightTurn(x->rightId);
            return smallLeftTurn(x);
        }
        if(balance(x)== -2){
                if (balance(x->leftId) > 0)
                    x->leftId = smallLeftTurn(x->leftId);
                return smallRightTurn(x);
        }
        fixheight(x);
        return x;
    }
 
 
 
    void  add(int x){
        root = add(root, x);
    }
 
    node* add(node* cur, int x){
        //cout<<"debug: debug" << endl;
        if (cur == nullptr ) {
            cur = new node;
            cur->value = x;
            cur->height = 0;
            cur->leftId=nullptr;
            cur->rightId=nullptr;
            return cur;
        }
        if (x < cur->value)
            cur->leftId = add(cur->leftId,x);
        else
            cur->rightId = add(cur->rightId,x);
     //   cout<<"debug: balance of "<<cur->value<<" = "<<balance(cur)<<endl;
        return rebalance(cur);
    }
 
    vector<niceOutput> outTree;
 
    void formOut(int &cur, node *x){
        if (x == nullptr) return;
        int curTemp = cur;
        outTree[cur-1].data = x->value;
        if (x->leftId == nullptr) outTree[cur-1].left = 0;
         else {
            outTree[cur - 1].left = cur + 1;
            cur++;
            formOut(cur, x->leftId);
        }
 
        if (x->rightId == nullptr) outTree[curTemp - 1].right = 0;
        else {
            outTree[curTemp - 1].right = cur + 1;
            cur++;
            formOut(cur, x->rightId);
        }
    }
 
    void print(int n) {
        outTree.resize(n);
        int i = 1;
        formOut(i, root);
 
        for (auto x: outTree) {
            cout << x.data << ' ' << x.left << ' ' << x.right << '\n';
        }
    }
 
 
 
};
 
 
 
int main() {
 
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    int n;
    cin >> n;
    int val,l,r;
    vector<AVLTree::node> arr(n + 1);
    for (auto i = 0; i < n; i++) {
        cin >> val >> l >> r;
        arr[i].value = val;
        if (l - 1 != -1) arr[i].leftId = &arr[l - 1];
        else arr[i].leftId = nullptr;
        if (r - 1 != -1) arr[i].rightId = &arr[r - 1];
        else arr[i].rightId = nullptr;
    }
 
    int x;
    cin >> x;
    AVLTree tree;
    if (n != 0) tree.root = &arr[0];
    tree.add(x);
 
    cout << n + 1 << '\n';
    tree.print(n + 1);
 
 /* for (int i = 0; i <=n; i++){
    cout<<arr[i].value<<endl;
    if (arr[i].leftId) cout << arr[i].leftId->value<<endl;
    else cout <<"no left child"<<endl;
    if (arr[i].rightId) cout << arr[i].rightId->value<<endl;
    else cout <<"no right child"<<endl;
  }*/
    return 0;
}
