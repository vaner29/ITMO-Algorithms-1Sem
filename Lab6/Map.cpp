#include <bits/stdc++.h>
using namespace std;
 
vector<pair<string, string>> HashTable[100001];
 
unsigned search(vector<pair<string, string>> a, string key) {
    for (unsigned i = 0; i < a.size(); i++)
        if (a[i].first == key)
            return i;
    return 0;
}
 
int hashId(string key){
    int temp = 0;
    for (char i : key){
        temp = temp * 7 + int(i);
    }
    return abs(temp % 100001);
}
 
 
 
int main() {
    ifstream fin("map.in");
    ofstream fout("map.out");
    string val;
    string key;
    string com;
    while (fin >> com) {
        if (com == "put") {
            fin >> key >> val;
            long i = hashId(key);
            unsigned id = search(HashTable[i], key);
            if (HashTable[i].empty() || HashTable[i][id].first != key)
                HashTable[i].emplace_back(key, val);
            else HashTable[i][id].second = val;
        }
        else if (com == "delete") {
            fin >> key;
            long i = hashId(key);
            unsigned id = search(HashTable[i], key);
            if (!HashTable[i].empty() && HashTable[i][id].first == key) {
                swap(HashTable[i][id], HashTable[i][HashTable[i].size() - 1]);
                HashTable[i].pop_back();
            }
        }
        else if (com == "get") {
            fin >> key;
            long i = hashId(key);
            unsigned id = search(HashTable[i], key);
            if (!HashTable[i].empty() && HashTable[i][id].first == key) {
                fout << HashTable[i][id].second << endl;
            }
            else {
                fout << "none\n";
            }
        }
 
    }
    return 0;
}
