/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        map<Node*, Node*> ogtocopy;

        Node* current = head;
        Node* copy = new Node(current->val);
        ogtocopy[current] = copy;
        Node* copyhead = copy;

        while (current->next != nullptr) {
            current = current->next;
            Node* temp = new Node(current->val);
            copy->next = temp;
            copy = copy->next;
            ogtocopy[current] = copy;
        }

        current = head;
        while (copyhead != nullptr) {
            copyhead->random = ogtocopy[current->random];
            copyhead = copyhead->next;
            current = current->next;
        }

        return ogtocopy[head];
    }
};
