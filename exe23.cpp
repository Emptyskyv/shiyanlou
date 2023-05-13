#include <iostream>
#include <vector>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int begin ,int end) {
        if (begin == end) {
            return lists[begin];
        } else if (begin > end) {
            return nullptr;
        }
        int mid = begin + (end - begin) / 2;

        return merge(mergeKLists(lists, begin, mid), mergeKLists(lists, mid + 1, end));
    }

    ListNode* merge(ListNode* f, ListNode* s) {
        ListNode* first = f;
        ListNode* second = s;
        if (first == nullptr) {
            return second;
        } else if (second == nullptr) {
            return first;
        }
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while (first && second) {
            if (first->val <= second->val) {
                temp->next = first;
                first = first->next;
            } else {
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }
        temp->next = (first ? first : second);

        return ans->next;
    }
};

int main() {
    ListNode* one = new ListNode(1);
    one->next = new ListNode(4);
    one->next->next = new ListNode(5);
    ListNode* two = new ListNode(1);
    two->next = new ListNode(3);
    two->next->next = new ListNode(4);
    ListNode* three = new ListNode(2);
    three->next = new ListNode(6);
    vector<ListNode*> list = {one, two, three};

    Solution ss;
    ss.mergeKLists(list);

    return 0;
}