#include <bits/stdc++.h>
using namespace std;
 
 
struct Node {
    int value;
    int leftId;
    int rightId;
    int height;
    Node() : leftId{-1}, rightId{-1}, height{-1} {}
    Node(int value, int leftId, int rightId) : value{value}, leftId{leftId}, rightId{rightId}, height{-1} {}
};
 
struct AVLTree {
    vector<Node> tree;
    int root;
    AVLTree() = default;
    explicit AVLTree(int n) : tree{vector<Node>(n)}, root{0} {}
 
    int height(int x) {
        if (x == -1) return 0;
        if (this->tree[x].height != -1) return this->tree[x].height;
        return this->tree[x].height = 1 + max(height(this->tree[x].leftId), height(this->tree[x].rightId));
    }
 
    int balance(int x) {
        return height(this->tree[x].rightId) - height(this->tree[x].leftId);
    }
 
 
    int smallLeftTurn(int x) {
        int y = this->tree[x].rightId;
        this->tree[x].rightId = this->tree[y].leftId;
        this->tree[y].leftId = x;
        this->tree[x].height = max(height(this->tree[x].leftId), height(this->tree[x].rightId)) + 1;
        this->tree[y].height = max(height(this->tree[y].leftId), height(this->tree[y].rightId)) + 1;
 
        this->root = y;
 
        return y;
    }
 
    int bigLeftTurn(int x) {
        this->tree[x].rightId = smallRightTurn(this->tree[x].rightId);
        return smallLeftTurn(x);
    }
 
        int smallRightTurn(int x) {
        int y = this->tree[x].leftId;
        this->tree[x].leftId = this->tree[y].rightId;
        this->tree[y].rightId = x;
        this->tree[x].height = max(height(this->tree[x].leftId), height(this->tree[x].rightId)) + 1;
        this->tree[y].height = max(height(this->tree[y].leftId), height(this->tree[y].rightId)) + 1;
        return y;
    }
 
    void treeTurn() {
        if (balance(this->tree[0].rightId) == -1) {
            bigLeftTurn(0);
        } else {
            smallLeftTurn(0);
        }
    }
 
 
    void print() {
        auto root = &this->tree[this->root];
        cout << root->value << ' ' << cmp(root->leftId, this->root) << ' ' << cmp(root->rightId, this->root) << '\n';
 
        for (int i = 0; i < this->tree.size(); i++) {
            if (i == this->root) continue;
            auto el = &this->tree[i];
            if (i < this->root) {
                cout << el->value << ' ' << cmp(el->leftId, this->root)
                     << ' ' << cmp(el->rightId, this->root) << '\n';
            } else {
                cout << el->value << ' ' << cmp(el->leftId, this->root) << ' ' << el->rightId + 1 << '\n';
            }
        }
    }
 
    int cmp(int child, int root) {
        if (child == -1) return 0;
        if (child <= root) return child + 2;
        else return child + 1;
    }
};
 
 
int main() {
 
    freopen("rotation.in", "r", stdin);
    freopen("rotation.out", "w", stdout);
    int n;
    cin >> n;
    auto *tree = new AVLTree(n);
    int val, l, r;
    for (int i = 0; i<n; i++) {
        cin >> val >> l >> r;
        tree->tree[i] = Node(val, l - 1, r - 1);
    }
 
    tree->treeTurn();
 
    cout << n << '\n';
 
    tree->print();
 
    return 0;
}
