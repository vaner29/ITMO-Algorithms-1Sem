#include <bits/stdc++.h>
using namespace std;
 
 
struct niceOutput {
    int data;
    int left;
    int right;
 
    niceOutput() = default;
 
    niceOutput(int data, int left, int right) : data{data}, left{left}, right{right} {}
};
 
 
class node{
public:
    node* parent;
    node* leftId;
    node* rightId;
    int value;
    int height;
 
    node(node* par = nullptr, int v = 0, int h = 1, node* l = nullptr, node* r = nullptr):
        parent(par), leftId(l), rightId(r), value(v), height(h)
    {}
};
 
 
    int height(node* x) {
        if (x == nullptr) return 0;
    return x -> height;
    }
 
    int balance(node* x) {
        if (x==nullptr) return 0;
        return height(x->rightId) - height(x->leftId);
    }
 
    int dfs(node* x){
    if (x == nullptr) return 0;
    x -> height = max(dfs(x -> leftId), dfs(x -> rightId)) + 1;
    return x -> height;
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
 
    node* bigLeftTurn(node* x){
    x -> rightId = smallRightTurn(x -> rightId);
    return smallLeftTurn(x);
}
 
    node* bigRightTurn(node* x){
    x -> leftId = smallLeftTurn(x -> leftId);
    return smallRightTurn(x);
}
 
    node* rebalance(node* x){
        if (x==nullptr) return nullptr;
        fixheight(x);
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
 
 
    node* add(node* root, int k, node* der = nullptr){
    if (root == nullptr) return new node(der, k);
    if (k < root -> value) root -> leftId = add(root -> leftId, k, root);
    else root -> rightId = add(root -> rightId, k, root);
    return rebalance(root);
}
 
    node* findmax(node* x){
 //       cout << "debug: node value = "<<x->value<<endl;
        if (x->rightId==nullptr) return x;
        return findmax(x->rightId);
    }
 
    node* removemax(node* x){
        if (x->rightId == nullptr)
            return x->leftId;
        x->rightId = removemax(x->rightId);
        return rebalance(x);
    }
 
    node* removeNode(node* x, int k){
        if (!x) return nullptr;
        if (x -> value == k && x -> leftId == nullptr && x -> rightId == nullptr){
        delete x;
        return nullptr;
    }
        if (k < x->value)
            x->leftId = removeNode(x->leftId, k);
        else if (k > x->value)
            x->rightId = removeNode(x->rightId, k);
        else {
      //          cout << "debug: x value = "<<x->value<<endl;
            node *lchild = x->leftId;
   //     cout << "debug: lchild value = "<<lchild->value<<endl;
            node *rchild = x->rightId;
      //      cout << "debug: rchild value = "<<rchild->value<<endl;
            delete (x);
            if (lchild == nullptr) return rchild;
            if (rchild == nullptr) return lchild;
            node* maxNode = findmax(lchild);
            maxNode->leftId = removemax(lchild);
            maxNode->rightId = rchild;
            return rebalance(maxNode);
        }
        return rebalance(x);
    }
 
    void print(node* s) {
    if (s == nullptr) return;
    queue<node*> q;
    q.push(s);
 
    int cnt = 1;
    while (!q.empty()) {
        node* v = q.front();
        q.pop();
        if (v == nullptr) break;
        int l = 0;
        int r = 0;
 
        if (v -> leftId != nullptr) {
            q.push(v -> leftId);
            l = ++ cnt;
        }
 
        if (v -> rightId != nullptr) {
            q.push(v -> rightId);
            r = ++ cnt;
        }
 
        cout << v -> value << " " << l << " " << r << endl;
    }
}
 
    node* find(node* root, int k){
    if (root == nullptr) return nullptr;
    if (root -> value == k) return root;
    if (k < root -> value) return find(root -> leftId, k);
    else return find(root -> rightId, k);
}
 
 
 
 
 
int main() {
 
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);
 
    int n; cin >> n;
 
    node* root = nullptr;
    char c;
    int i = 0;
    while (i < n){
        cin >> c;
        int x; cin >> x;
        if (c == 'A'){
            if (find(root, x) == nullptr) root = add(root, x);
            cout << balance(root) << endl;
        }
        if (c == 'D'){
            if (find(root, x) != nullptr) root = removeNode(root, x);
            cout << balance(root) << endl;
        }
        if (c == 'C'){
            if (find(root, x) == nullptr) cout << "N" << endl;
            else cout << "Y" << endl;
        }
        i ++;
    }
}
