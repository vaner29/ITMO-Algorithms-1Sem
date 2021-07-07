#include <bits/stdc++.h>
using namespace std;
 
 
int findKelem(vector<int> &arr, int first, int last, int k) {
    int i = first, j = last;
    int piv = arr[last];
    while (i <= j) {
        while (arr[i] < piv)
            i++;
        while (arr[j] > piv)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    if (k <= j )
        return findKelem(arr,first, j, k);
    if (i <= k)
        return findKelem(arr,i, last, k);
    return arr[k];
}
 
 
int main() {
    int k, A, B, C,n ;
    cin >> n >> k >> A >> B >> C;
    vector <int> arr(n);
    cin >> arr[0] >> arr[1];
    for (int i = 2; i < n ; i++){
        arr[i] = A * arr[i-2] + B * arr[i-1] + C;
    }
    cout << findKelem(arr, 0, n - 1, k - 1);
 
return 0;
}
