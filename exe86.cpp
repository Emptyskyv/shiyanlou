#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return head;
        }
        ListNode *small = new ListNode(0, head);
        ListNode *big = new ListNode();
        ListNode *last = small;
        ListNode *temp1 = head;
        ListNode *temp2 = big;
        while (temp1) {
            if (temp1->val < x) {
                last = temp1;
                temp1 = temp1->next;
            } else {
                temp2->next = temp1;
                temp2 = temp2->next;
                last->next = temp1->next;
                temp1 = temp1->next;
                temp2->next = nullptr;
            }
        }
        last->next = big->next;

        return small->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(5);
    temp = temp->next;
    temp->next = new ListNode(2);
    Solution ss;
    ss.partition(head, 3);
    auto cmp = [](ListNode* a, ListNode* b) {
        return a->val >= b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);


    return 0;
}