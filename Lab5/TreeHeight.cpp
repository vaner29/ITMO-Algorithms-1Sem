#include <bits/stdc++.h>
using namespace std;
 
typedef struct Point{
    int value = 0;
    int height = 1;
    Point* parent = nullptr;
} Point;
 
int main(){
    freopen("height.in", "r", stdin);
    freopen("height.out","w", stdout);
    int n, l, r, maxHeight = 0;
    cin >> n;
    Point tree[n];
    for (int i = 0; i < n; i++){
        cin >> tree[i].value >> l >> r;
        tree[l-1].parent = &tree[i];
        tree[r-1].parent = &tree[i];
        if (tree[i].parent != nullptr)
            tree[i].height = tree[i].parent->height + 1;
        if (tree[i].height > maxHeight)
            maxHeight = tree[i].height;
    }
    cout << maxHeight;
 
}
