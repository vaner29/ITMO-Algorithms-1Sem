#include <bits/stdc++.h>
using namespace std;
 
 
 
struct miniMap{
    string key;
    vector <vector <string> > element;
    miniMap(){
        element.resize(316);
    }
};
 
struct multiMap{
    vector <vector<miniMap>> minimap;
    multiMap(){
        minimap.resize(100005);
    }
};
 
multiMap mMap;
 
int hashId(const string& key, int hashSize){
    int hashed = 0;
    int multiplier = 1;
    for (char i : key){
        hashed += multiplier * (int)i;
        hashed %= hashSize;
        multiplier = (multiplier * 41) % hashSize;
    }
    return hashed;
}
 
 
void put(const string& key, const string& val){
    int keyHash = hashId(key, 100005);
    for (auto & i : mMap.minimap[keyHash]){
        if (i.key == key){
            int elHash = hashId(val, 316);
            for (const auto & j : i.element[elHash]){
                if (j == val)
                    return;
            }
            i.element[elHash].push_back(val);
            return;
        }
    }
    miniMap* newminiMap = new miniMap;
    newminiMap->key = key;
    newminiMap->element[hashId(val, 316)].push_back(val);
    mMap.minimap[keyHash].push_back(*newminiMap);
    delete newminiMap;
}
 
void deleteOne(const string& key, const string& val){
    int keyHash = hashId(key, 100005);
    for (auto & i : mMap.minimap[keyHash]){
        if (i.key == key){
            int elHash = hashId(val, 316);
            for (int j = 0; j < i.element[elHash].size(); j++){
                if (i.element[elHash][j] == val) {
                    i.element[elHash].erase(i.element[elHash].begin() + j);
                    return;
                }
            }
        }
    }
}
 
void deleteAll(const string& key){
    int keyHash = hashId(key, 100005);
    for (auto & i : mMap.minimap[keyHash]){
        if (i.key == key){
            for(auto & j : i.element){
                while(!j.empty())
                    j.pop_back();
            }
            return;
        }
    }
}
 
vector<string> Get (const string& key){
    vector<string> Result;
    int keyHash = hashId(key, 100005);
    for (auto & i : mMap.minimap[keyHash]){
        if (i.key == key){
            for(auto & j : i.element){
                for(const auto & k : j) {
                    Result.push_back(k);
                }
            }
            return Result;
        }
    }
    return Result;
}
 
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("multimap.in");
    fout.open("multimap.out");
    while(!fin.eof()) {
        string com;
        fin >> com;
        if (com == "put") {
            string first, second;
            fin >> first >> second;
            put(first, second);
        }
        if (com == "delete") {
            string first, second;
            fin >> first >> second;
            deleteOne(first, second);
        }
        if (com == "deleteall") {
            string first;
            fin >> first;
            deleteAll(first);
        }
        if (com == "get") {
            string first;
            fin >> first;
            vector<string> getA = Get(first);
            fout << getA.size() << ' ';
            for (const string& i : getA)
                fout << i << ' ';
            fout << "\n";
        }
 
    }
    fin.close();
    fout.close();
    return 0;
}
