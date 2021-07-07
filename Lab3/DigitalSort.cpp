#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
void radixSort(vector <string>& a, int n, int i) {
    vector <string> tempsort (n);
    int arrpos=0;
    for (char curchar = 'a'; curchar < 'z'; curchar++){
        for (int j = 0; j < n; j++){
            if (a[j][i] == curchar){
                tempsort[arrpos] = a[j];
                arrpos++;
            }
        }
    }
    for (int j = 0; j < n; j++){
        a[j] = tempsort[j];
    }
}
 
 
int main()
{
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out","w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = m - 1; i >= m-k; i--){
        radixSort(a,n,i);
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}
