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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* end = head;

        while (end != nullptr) { //reversing the linked list
            ListNode* temp = end->next;
            end->next = prev;
            prev = end;
            end = temp;
        }
        end = prev;
        prev = prev->next;

        ListNode* realEnd = end;
        n -= 2;

        if (n == -1) {
            end->next = nullptr;
        } else {
                while (n > 0) {
                prev = prev->next;
                end = end->next;
                n--;
            }

            end->next = prev->next;
            prev->next = nullptr;
        }
        if (n == -1) {
            realEnd = prev;
        }

        ListNode* current = realEnd;
        ListNode* prev2 = nullptr;

        while (current != nullptr) { //reversing it back
            ListNode* temp2 = current->next;
            current->next = prev2;
            prev2 = current;
            current = temp2;
        }

        return prev2;
    }
};
