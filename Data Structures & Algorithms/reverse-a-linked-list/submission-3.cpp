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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        if (head->next != nullptr && head->next->next == nullptr) {
            curr->next = prev;
            prev->next = nullptr;
            return curr;
        }
        ListNode* next = curr->next;

        curr->next = prev;
        prev->next = next;
        ListNode* temp = next->next;
        next->next = curr;
        prev->next = temp;
        while (temp != nullptr) {
            temp = temp->next;
            prev->next->next = next;
            next = prev->next;
            prev->next = temp;
        }

        return next;
        
        



    }
};
