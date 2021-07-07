#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
   // freopen("antiqs.in", "r", stdin);
 //   freopen("antiqs.out","w", stdout);
 
    int n,j;
    cin >> n;
    vector <int> a(n,0);
    for (int i = 0; i < n; i++){
        a[i] = i + 1;
    }
    int temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = a[i / 2];
        a[i / 2] = temp;
    }
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
 
return 0;
}
