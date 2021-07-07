#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    freopen("sortland.in", "r", stdin);
    freopen("sortland.out","w", stdout);
    int n;
 
    cin >> n;
 
    vector<double> a(n);
    vector<int>id(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        id[i] = i+1;
    }
    int tid,j;
    double t;
    for (int i = 1; i < n; i ++){
            j = i - 1;
            t = a[i];
            tid = i+1;
            while (j > -1 && a[j] > t) {
                a[j + 1] = a[j];
                id[j + 1] = id[j];
                j = j - 1;
            }
            a[j + 1] = t;
            id[j + 1] = tid;
    }
 
        cout << id[0] << ' ' << id[trunc(n/2)] << ' ' << id[n-1];
}
