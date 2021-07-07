#include <bits/stdc++.h>
using namespace std;
 
double buildLights(vector <double> a, int n) {
    double left = a[0], right = 0;
    while (left - right > 0.000001) {
        a[1] = (left + right) / 2;
        bool down = true;
        for (int i = 2; i < n; i++) {
            a[i] = 2 * a[i - 1] - a[i - 2] + 2;
            if (a[i] < 0) {
                down = false;
                break;
            }
        }
        if (down)
            left = a[1];
        else
            right = a[1];
    }
    return a[n - 1];
}
 
int main(){
   // freopen("garland.in", "r", stdin);
   // freopen("garland.out","w", stdout);
    int n;
 
    cin >> n;
    vector <double> a(n,0);
    cin >>a[0];
    cout << fixed;
    cout.precision(2);
    cout << buildLights(a, n);
 
}
