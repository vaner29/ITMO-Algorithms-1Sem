#include <bits/stdc++.h>
using namespace std;
 
struct Queue{
    long val;
    Queue *last = NULL;
};
 
Queue* add(long val, Queue *last){
    Queue *newS = (Queue*)malloc(sizeof(Queue));
    newS->val = val;
    newS->last = last;
    return newS;
}
 
int main() {
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    long n;
    fin >> n;
    char com;
    long val;
    Queue* que = NULL;
    for (int i = 0; i < n; i++) {
        fin >> com;
        if (com == '+') {
            fin >> val;
            que = add(val, que);
        }
        else {
            Queue* first = que;
            if ( first->last != NULL) {
                while (first->last->last != NULL){
                    first = first->last;
                }
                fout << first->last->val << "\n";
                first->last = NULL;
            }
            else {
                fout << first->val <<"\n";
                que = NULL;
            }
        }
    }
}
