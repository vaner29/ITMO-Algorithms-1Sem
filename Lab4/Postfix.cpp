#include <bits/stdc++.h>
using namespace std;
 
struct Stack{
    long long val;
    Stack *last = NULL;
};
 
Stack* add(long long val, Stack *last){
    Stack *newS = (Stack*)malloc(sizeof(Stack));
    newS->val = val;
    newS->last = last;
    return newS;
}
 
int main() {
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    string s;
    getline(fin, s);
    char com;
    int i = 0;
    Stack* a = NULL;
    while (i < s.length()){
        com = s[i];
        if (com == '+'){
            a->last->val = a->last->val + a->val;
            a = a->last;
        } else
        if (com == '-'){
            a->last->val = a->last->val - a->val;
            a = a->last;
        } else
        if (com == '*'){
            a->last->val = a->last->val * a->val;
            a = a->last;
        }
        else  if ((int)com >= 48 && (int)com <= 58){
            a = add((int)com - 48, a);
        }
        i = i+2;
        if (i > 197) break;
    }
    fout << a->val;
return 0;
}
