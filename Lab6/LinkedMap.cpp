#include <bits/stdc++.h>
using namespace std;
 
struct hash_table {
    hash_table* prev = nullptr;
    hash_table* prevOrderly = nullptr;
    string key;
    string value;
    hash_table* next = nullptr;
    hash_table* nextOrderly = nullptr;
};
hash_table* table[1000000];
 
hash_table* newHash(string& key, string& value) {
    auto* hash = new hash_table();
    hash->prev = nullptr;
    hash->prevOrderly = nullptr;
    hash->key = key;
    hash->value = value;
    hash->nextOrderly = nullptr;
    hash->next = nullptr;
    return hash;
}
 
hash_table* add(hash_table*& last, string& key, string& value) {
    hash_table* hash = newHash(key, value);
    hash->prev = last;
    last->next = hash;
    return hash;
}
 
int hashId(string& key) {
    const int p = 31;
    int hash = 0, p_pow = 1;
    for (char i : key){
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    if (hash >= 0) return hash % 1000000;
    else return (1000000 - abs(hash) % 1000000);
}
 
hash_table* put(string& key, string& value, hash_table*& last) {
    int hash = hashId(key);
    hash_table* head = table[hash];
    if (head) {
        hash_table* cur = head;
        while (cur->next) {
            if (cur->key == key) {
                cur->value = value;
                return nullptr;
            }
            cur = cur->next;
        }
        if (cur->key != key) {
            hash_table* new_hash = add(cur, key, value);
            new_hash->prevOrderly = last;
            if (last) last->nextOrderly = new_hash;
            return new_hash;
        }
        else {
            cur->value = value;
            return nullptr;
        }
    }
    else {
        table[hash] = newHash(key, value);
        table[hash]->prevOrderly = last;
        if (last) last->nextOrderly = table[hash];
        return table[hash];
    }
}
 
void hashDelete(string& key, hash_table*& last) {
    int hash = hashId(key);
    hash_table* cur = table[hash];
    while (cur) {
        if (cur->key == key) {
            if (last == cur)last = cur->prevOrderly;
            if (cur->prevOrderly) cur->prevOrderly->nextOrderly = cur->nextOrderly;
            if (cur->nextOrderly) cur->nextOrderly->prevOrderly = cur->prevOrderly;
            if (cur->prev)cur->prev->next = cur->next;
            if (cur->next)cur->next->prev = cur->prev;
            if (cur == table[hash]) table[hash] = nullptr;
            free(cur);
            return;
        }
        cur = cur->next;
    }
}
 
void get(string& key) {
    hash_table* cur = table[hashId(key)];
    while (cur) {
        if (cur->key == key) {
            cout << cur->value << "\n";
            return;
        }
        cur = cur->next;
    }
    cout << "none" << '\n';
}
 
hash_table* hashFind(string& key) {
    hash_table* cur = table[hashId(key)];
    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}
 
void prev(string& key) {
    hash_table* element = hashFind(key);
    if (element && element->prevOrderly) cout << element->prevOrderly->value << "\n";
    else cout << "none" << '\n';
}
 
void next(string& key) {
    hash_table* element = hashFind(key);
    if (element && element->nextOrderly) cout << element->nextOrderly->value << "\n";
    else cout << "none" << '\n';
}
 
int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    hash_table* last = nullptr;
    string command;
    string key;
    string value;
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            hash_table* pointer = put(key, value, last);
            if (pointer) last = pointer;
        }
 
        else if (command == "delete") hashDelete(key, last);
        else if (command == "get") get(key);
        else if (command == "prev") prev(key);
        else if (command == "next") next(key);
    }
    return 0;
}
