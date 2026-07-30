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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3;
        ListNode* head;
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        if (list1->val <= list2->val) {
            list3 = list1;
            head = list3;
            list1 = list1->next;
        } else {
            list3 = list2;
            head = list3;
            list2 = list2->next;
        }

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                list3->next = list1;
                list1 = list1->next;
                list3 = list3->next;
            } else {
                list3->next = list2;
                list2 = list2->next;
                list3 = list3->next;
            }
        }

        if (list1 != nullptr) {
            list3->next = list1;
        } else if (list2 != nullptr) {
            list3->next = list2;
        }

        return head;
    }
};
