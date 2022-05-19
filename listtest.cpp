#include <iostream>
#include <vector>

using namespace std;
typedef struct link {
    int val = 0;
    struct link *next = NULL;
    struct link *last = NULL;
} llist;

class moticlist {

private:
    llist *head;
    llist *tail;
public:
    moticlist() {
        head = new llist();
        tail = new llist();
        head->next = tail;
        tail->last = head;
    }

    void push(llist *inode) {
        llist *temp = head->next;
        while (temp != tail && temp->val < inode->val) {
            temp = temp->next;
        }
        inode->next = temp;
        inode->last = head;
        temp->last = inode;
        head->next = inode;
    }

    llist* returnmax() {
        return tail->last == head ? NULL : tail->last;
    }

    void pop(llist *inode) {
        if (tail->last == inode) {
            tail->last = tail->last->last;
            tail->last->next = tail;
        }
    }
    void show() {
        llist *temp = head->next;
        while (temp != tail) {
            cout << temp->val << ' ';
            temp = temp->next;
        }
    }
};

int main(void) {
    moticlist test;
    vector<int> nums = {1, 3, -1, -3, 5, 3};
    for (auto x: nums) {
        llist *temp = new llist();
        temp->val = x;
        test.push(temp);
    }
    test.show();

    return 0;
}