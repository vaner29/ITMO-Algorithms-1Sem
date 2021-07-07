#include <bits/stdc++.h>
using namespace std;
 
typedef struct Point{
    int value = 0;
    int height = 1;
    int heightLeft=height;
    int heightRight=height;
    Point* parent = nullptr;
} Point;
 
int main(){
    freopen("balance.in", "r", stdin);
    freopen("balance.out","w", stdout);
    int n, l, r, maxHeight = 0;
    cin >> n;
    Point tree[n];
    for (int i = 0; i < n; i++){
        cin >> tree[i].value >> l >> r;
        tree[l-1].parent = &tree[i];
        tree[r-1].parent = &tree[i];
        if (tree[i].parent != nullptr)
            tree[i].height = tree[i].parent->height + 1;
        tree[i].heightRight = tree[i].height;
        tree[i].heightLeft = tree[i].height;
    }
    for (int i = n-1; i > 0; i--){
       // cout << tree[i].value <<' '<<tree[i].parent->value<<endl;
        if (tree[i].value > tree[i].parent->value)
            tree[i].parent->heightRight = tree[i].height;
        else tree[i].parent->heightLeft = tree[i].height;
        if (tree[i].height > tree[i].parent->height)
            tree[i].parent->height = tree[i].height;
       // cout <<"parents heights:"<< tree[i].parent->heightLeft <<' '<< tree[i].parent->heightRight<<endl;
    }
    for (int i = 0; i < n; i++){
        cout << tree[i].heightRight-tree[i].heightLeft<<endl;
        //cout<< tree[i].height <<' '<< tree[i].heightLeft<<' '<<tree[i].heightRight << endl;
    }
 
return 0;
}
