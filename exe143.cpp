#include <iostream>

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
    void reorderList(ListNode* head) {
        ListNode* fast = new ListNode(0, head);
        ListNode* slow = fast;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverse(slow->next);
        ListNode* t = new ListNode();
        while (slow) {
            t->next = head;
            head = head->next;
            t = t->next;
            t->next = slow;
            slow = slow->next;
            t = t->next;
        }
        if (head) {
            t->next = head;
            head->next = nullptr;
        }
    }

    ListNode* reverse(ListNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        ListNode* ans = reverse(root->next);
        if (ans) {
            root->next->next = root;
            root->next = nullptr;
            return ans;
        }

        return root;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution ss;
    ss.reorderList(head);

    return 0;
}

