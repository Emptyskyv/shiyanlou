#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* indexA = headA;
        ListNode* indexB = headB;
        bool flagA = true;
        bool flagB = true;
        while (indexA != indexB) {
            if (flagA && !indexA->next) {
                indexA = headB;
                flagA = false;
            }
            if (flagB && !indexB->next) {
                indexB = headA;
                flagB = false;
            }
            indexA = indexA->next;
            indexB = indexB->next;
        }

        return indexA;
    }
};

int main() {
//    ListNode* c1 = new ListNode(8);
//    c1->next = new ListNode(4);
//    c1->next->next = new ListNode(5);
//    ListNode* a1 = new ListNode(4);
//    a1->next = new ListNode(1);
//    a1->next->next = c1;
//    ListNode* b1 = new ListNode(5);
//    b1->next = new ListNode(6);
//    b1->next->next = new ListNode(1);
//    b1->next->next->next = c1;
//    Solution ss;
//    ss.getIntersectionNode(a1, b1);
    vector<char> s = {'H', 's', 'l', 'l', 'o'};
    int head = 0;
    int tail = s.size() - 1;
    while (head != tail) {
        swap(s[head++], s[tail--]);
    }

    return 0;
}

