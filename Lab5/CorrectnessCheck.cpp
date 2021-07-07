#include <bits/stdc++.h>
using namespace std;
 
typedef struct Point{
    int value = 0;
    int min;
    int max;
    Point* parent = nullptr;
    Point* lchild = nullptr;
    Point* rchild = nullptr;
 
} Point;
 
int main(){
    freopen("check.in", "r", stdin);
    freopen("check.out","w", stdout);
    int n, l, r;
    bool flag = false;;
    cin >> n;
    Point tree[n];
    for (int i = 0; i < n; i++){
        cin >> tree[i].value >> l >> r;
        if (l != 0) {
            tree[i].lchild = &tree[l-1];
            tree[l-1].parent = &tree[i];
        }
        if (r != 0) {
            tree[i].rchild = &tree[r-1];
            tree[r-1].parent = &tree[i];
        }
        if (i != 0) {
             if (tree[i].parent->value >= tree[i].value && tree[i].parent->rchild == &tree[i]) flag = true;
             else if (tree[i].parent->value <= tree[i].value && tree[i].parent->lchild == &tree[i]) flag = true;
             else if (tree[i].parent->value > tree[i].value && tree[i].value <= tree[i].parent->min) flag = true;
             else if (tree[i].parent->value < tree[i].value && tree[i].value >= tree[i].parent->max) flag = true;
            if (tree[i].parent->value > tree[i].value) {
                tree[i].max = tree[i].parent->value;
                tree[i].min = tree[i].parent->min;
            }else if (tree[i].parent->value < tree[i].value) {
                tree[i].min = tree[i].parent->value;
                tree[i].max = tree[i].parent->max;
            }
        } else {
            tree[i].min = INT32_MIN;
            tree[i].max = INT32_MAX;
        }
    }
    if (flag) cout << "NO";
    else cout << "YES";
 
}
