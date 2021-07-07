#include <bits/stdc++.h>
using namespace std;
 
vector<long> HashTable[1000001];
 
unsigned search(vector<long> a, long key) {
    for (unsigned i = 0; i < a.size(); i++)
        if (a[i] == key)
            return i;
    return 0;
}
 
 
 
int main() {
    ifstream fin("set.in");
    ofstream fout("set.out");
    long key;
    string com;
    while (fin >> com >> key) {
        long i = abs(key % 1000001);
        unsigned id = search(HashTable[i], key);
        if (com == "insert") {
                if (HashTable[i].empty() || HashTable[i][id] != key)
                HashTable[i].push_back(key);
                }
        else if (com == "delete") {
            if (!HashTable[i].empty() && HashTable[i][id] == key) {
                swap(HashTable[i][id], HashTable[i][HashTable[i].size() - 1]);
                HashTable[i].pop_back();
            }
        }
        else if (com == "exists") {
            if (!HashTable[i].empty() && HashTable[i][id] == key) {
                fout << "true\n";
            }
            else {
                fout << "false\n";
            }
        }
 
    }
    return 0;
}
