//соответственно, слияние, qsort законтрен тестами

#include <bits/stdc++.h>
 
using namespace std;
int n;
vector <int> arr(300000);
void Merge(int left, int mid, int right){
    int bord1 = mid - left + 1;
    int bord2 = right - mid;
    vector <int> L (bord1+1);   //+2?
    vector <int> R (bord2+1); //+2?
    int i,j;
    for (i = 0; i < bord1; i++){
        L[i] = arr[left + i];
    }
    for (j = 0; j < bord2; j++){
        R[j] = arr[mid+j+1];
    }
    L[bord1] = 2147483647;
    R[bord2] = 2147483647;
    i = 0;
    j = 0;
    for (int k = left; k <= right; k++){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
}
 
void Msort (int left, int right){
    if (left < right) {
        int mid = (left + right) / 2;
        Msort(left, mid);
        Msort(mid + 1, right);
        Merge(left, mid, right);
    }
}
int main() {
    //n = 6;
    cin >> n;
   for (int i = 0; i < n; i++){
    //arr = {6, 5, 4, 3, 2, 1};
    cin >> arr[i];
    }
    Msort (0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
 
return 0;
}
