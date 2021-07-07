#include <bits/stdc++.h>
using namespace std;
 
int main(){
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out","w", stdout);
    long n;
    cin >> n;
    vector <long> arr(n+1,0);
    for (int i = 1; i < n+1; i++){
        cin >> arr[i];
    }
    for (int i = 1; i < n / 2 + 2; i++){
        if (i * 2 + 1 >= n) break;
        if (arr[i*2] < arr[i] || arr[i*2+1] < arr[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
