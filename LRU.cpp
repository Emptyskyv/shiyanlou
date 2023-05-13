#include <iostream>
#include <unordered_map>

using namespace std;

struct LinkNode {
    int key, val;
    LinkNode* next;
    LinkNode* pre;
    LinkNode(): key(0), val(0), next(nullptr), pre(nullptr) {};
    LinkNode(int _key, int _val): key(_key), val(_val), next(nullptr), pre(nullptr) {};
};

class LRUCache {
private:
    int size, cap;
    LinkNode* first;
    LinkNode* last;
    unordered_map<int, LinkNode*> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        first = new LinkNode();
        last = new LinkNode();
        first->next = last;
        last->pre = first;
    }

    int get(int key) {
        if (m.count(key) != 0) {
            movetofirst(key);
            return m[key]->val;
        }

        return -1;
    }

    void put(int key, int value) {
        if (m.count(key) != 0) {
            m[key]->val = value;
        } else {
            if (size == cap) {
                deletelast();
                size--;
            }
            addtofirst(key, value);
            size++;
        }
    }

    void movetofirst(int key) {
        LinkNode* temp = m[key];
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;
        first->next->pre = temp;
        temp->next = first->next;
        first->next = temp;
        temp->pre = first;
    }

    void addtofirst(int key, int val) {
        LinkNode* temp = new LinkNode(key, val);
        m[key] = temp;
        //size++;
        temp->next = first->next;
        first->next->pre = temp;
        first->next = temp;
        temp->pre = first;
    }

    void deletenode(int key) {
        LinkNode* temp = m[key];
        m.erase(key);
        temp->next->pre = temp->pre;
        temp->pre->next = temp->next;
        //delete temp;
        //temp = nullptr;
    }

    void deletelast() {
        deletenode(last->pre->key);
    }
};
int main() {
//    LRUCache lru(2);
//    lru.put(2, 1);
//    lru.put(1, 1);
//    lru.put(2, 3);
//    lru.put(4, 1);
//    lru.get(1);
//    lru.get(2);
    string temp = "anannag";
    cout << temp.substr(temp.size());


    return 0;
}