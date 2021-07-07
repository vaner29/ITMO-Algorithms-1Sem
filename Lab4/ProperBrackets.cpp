#include <bits/stdc++.h>
using namespace std;
 
struct Stack{
    char val;
    Stack *last;
};
 
Stack* add(char val, Stack *last){
    Stack *newS = (Stack*)malloc(sizeof(Stack));
    newS->val = val;
    newS->last = last;
    return newS;
}
 
int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    bool flag = true;
    string s;
    char valIn;
    Stack* stac;
    int k;
    while (fin >> s){
        k = 0;
        for (int i = 0; i < s.length(); i++){
                valIn = s[i];
                flag = true;
                if (valIn == '(' || valIn == '[') {
                    k++;
                    stac = add(valIn, stac);
                }
                else {
                    if ((valIn == ')' && stac->val != '(') || (valIn == ']' && stac->val != '[') || (k == 0)){
                        flag = false;
                        break;
                }
                else  {
                        stac = stac -> last;
                        k--;
                }
            }
        }
        if (flag && k == 0) fout << "YES\n";
        else fout << "NO\n";
    }
    return 0;
}
