#include <bits/stdc++.h>
 
using namespace std;
 
struct Runner{
    string Country;
    string Name;
    int Num;
} ;
 
vector <Runner> arr(100000);
void Merge(int left, int mid, int right){
    int bord1 = mid - left + 1;
    int bord2 = right - mid;
    vector <Runner> L (bord1+1);
    vector <Runner> R (bord2+1);
    int i,j;
    for (i = 0; i < bord1; i++){
        L[i] = arr[left + i];
    }
    for (j = 0; j < bord2; j++){
        R[j] = arr[mid+j+1];
    }
    L[bord1].Country = "~";
    R[bord2].Country = "~";
    i = 0;
    j = 0;
    for (int k = left; k <= right; k++){
        if (L[i].Country <= R[j].Country) {
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
    freopen("race.in", "r", stdin);
    freopen("race.out","w", stdout);
    int n;
    cin >> n;
   for (int i = 0; i < n; i++){
    cin >> arr[i].Country >> arr[i].Name;
    arr[i].Num = i;
    }
    Msort (0, n-1);
    string prev;
    for (int i = 0; i < n; i++){
            if (prev != arr[i].Country){
                cout << "=== " << arr[i].Country << " ===\n";
                prev = arr[i].Country;
            }
        cout << arr[i].Name << "\n";
    }
 
return 0;
}
