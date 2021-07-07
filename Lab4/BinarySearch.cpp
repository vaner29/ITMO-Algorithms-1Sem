#include <bits/stdc++.h>
using namespace std;
int id1, id2;
 
int binSearchFirst(vector <int> &a, int x){
    int l = -1;
    int r = a.size();
    int m;
    while (r > l + 1){
        if (a[r] == x && a[l] == x) {
            break;
        }
        m = (l + r) / 2;
        if (a[m] < x) l = m;
        else r = m;
    }
    if (a[r] != x) return -1;
    else return r + 1;
}
 
int binSearchLast(vector <int> &a, int x){
    int l = -1;
    int r = a.size();
    int m;
    while (r > l + 1){
        if (a[r] == x && a[l] == x) {
            break;
        }
        m = (l + r) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    if (a[l] != x) return -1;
    else return l + 1;
}
 
int main(){
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out","w", stdout);
    int n;
    cin >> n;
    vector <int> a (n,0);
    for (int i = 0; i < n; i++){
        cin >>a[i];
    }
    cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        cout << binSearchFirst(a,x) << ' ' << binSearchLast(a,x) << endl;
    }
 
}
