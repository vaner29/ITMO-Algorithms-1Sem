#include <bits/stdc++.h>
 
using namespace std;
 
int Max(int a, int b){
    if (a > b) return a;
    else return b;
}
 
int main() {
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out","w", stdout);
 
    int h, w;
 
    cin >> h >> w;
 
    vector <vector <int>> field (h);
    for (int i = 0; i < h; i++){
            field[i].resize(w);
            for (int j = 0; j < w; j++) {
                     cin >> field[i][j];
            }
    }
 
    for (int i = h-2; i >= 0; i--){
        field[i][0] = field[i][0] + field[i+1][0];
    }
    for (int i = 1; i < w; i++) {
        field[h-1][i] =field[h-1][i] + field[h-1][i-1];
    }
 
 
   for (int i = h - 2; i >= 0 ; i--){
            for (int j = 1; j < w; j++) {
                     field[i][j] = Max(field[i+1][j], field[i][j-1]) + field[i][j];
            }
   }
 
    cout << field[0][w-1];
}
