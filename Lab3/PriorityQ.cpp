#include <bits/stdc++.h>
using namespace std;
 
long n = 0;
pair <long, long> a[1000000];
 
void siftDown(long i){
    long largest;
    long l = 2 * i + 1;
    long r = 2 * i + 2;
    if (l < n && a[l].first < a[i].first)
        largest = l;
    else
        largest = i;
    if (r < n && a[r].first < a[largest].first)
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        siftDown(largest);
    }
}
 
void siftUp(long i){
    if (i != 0 && a[i].first < a[(i - 1) / 2].first){
        swap(a[i],a[( i - 1) / 2]);
        siftUp((i - 1 ) / 2);
    }
}
 
void pushQueue(long val, long pos){
    n++;
    a[n-1].first = val;
    a[n-1].second = pos;
    siftUp(n - 1);
}
 
void extractMin(){
    if (n == 0) cout <<"*\n";
    else {
        cout << a[0].first << "\n";
        swap(a[0], a[n - 1]);
        n--;
        siftDown(0);
    }
}
 
void decreaseKey(long pos, long dec){
    long j;
    for (long i = 0; i < n; i++){
        if (a[i].second == pos) j = i;
    }
    a[j].first = dec;
        if (j != 0 && a[j].first < a[(j - 1) / 2].first) siftUp(j);
        else siftDown(j);
}
 
int main() {
    ifstream fin("priorityqueue.in");
    ofstream fout("priorityqueue.out");
 
    string command;
    int i = 0;
    while (fin >> command) {
        i++;
        if (command.length() == 0)
            break;
        if (command == "push") {
            long val;
            fin >> val;
            pushQueue(val, i);
 
        } else if (command == "extract-min") {
            extractMin();
 
        } else if (command == "decrease-key") {
            long x, y;
            fin >> x >> y;
            decreaseKey(x, y);
 
        } else {
            break;
        }
    }
    return 0;
}
