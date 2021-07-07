#include <bits/stdc++.h>
using namespace std;
 
struct Stack{
    long val;
    Stack *last;
};
 
Stack* add(long val, Stack *last){
    Stack *newS = (Stack*)malloc(sizeof(Stack));
    newS->val = val;
    newS->last = last;
    return newS;
}
 
int main() {
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    long n;
    fin >> n;
    char com;
    long val;
    Stack* stac;
    for (int i = 0; i < n; i++) {
        fin >> com;
        if (com == '+') {
            fin >> val;
            stac = add(val, stac);
        } else {
            fout << stac->val << "\n";
            stac = stac->last;
        }
    }
}
