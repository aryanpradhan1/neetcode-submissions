/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        map<ListNode*, ListNode*> nodes;

        if (head == nullptr) {
            return false;
        }

        while (head->next != nullptr) {
            if (nodes.contains(head->next)) {
                return true;
            }

            nodes[head] = head->next;
            head = head->next;
        }

        return false;
    }
};
